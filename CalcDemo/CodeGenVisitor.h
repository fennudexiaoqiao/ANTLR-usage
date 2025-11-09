#ifndef CODEGENVISITOR_H
#define CODEGENVISITOR_H

#include "anltr/CalcBaseVisitor.h"
#include <sstream>

class CodeGenVisitor : public CalcBaseVisitor {
private:
    std::ostringstream code;
    int tempVarCount = 0;

    std::string  newTemp() {
        return "t" + std::to_string(tempVarCount++);
    }

public:
    std::any visitProg(CalcParser::ProgContext *ctx) override {
        code << ".data\n";
        code << "newline: .asciiz \"\\n\"\n";
        code << ".text\n";
        code << ".globl main\n\n";
        code << "main:\n";

        for (auto stat : ctx->stat()) {
            visit(stat);
        }

        code << "li $v0, 10     # exit\n";
        code << "syscall\n";

        return nullptr;
    }

    std::any visitAssign(CalcParser::AssignContext *ctx) override {
        std::string var = ctx->ID()->getText();
        auto result = visit(ctx->expr());
        std::string temp = std::any_cast<std::string>(result);

        code << "sw " << temp << ", " << var << "  # store " << var << "\n";
        return var;
    }

    std::any visitPrintExpr(CalcParser::PrintExprContext *ctx) override {
        auto result = visit(ctx->expr());
        std::string temp = std::any_cast<std::string>(result);

        code << "move $a0, " << temp << "\n";
        code << "li $v0, 1     # print integer\n";
        code << "syscall\n";
        code << "la $a0, newline\n";
        code << "li $v0, 4     # print string\n";
        code << "syscall\n";

        return temp;
    }

    std::any visitInt(CalcParser::IntContext *ctx) override {
        std::string temp = newTemp();
        int value = std::stoi(ctx->INT()->getText());
        code << "li " << temp << ", " << value << "\n";
        return temp;
    }

    std::any visitId(CalcParser::IdContext *ctx) override {
        std::string var = ctx->ID()->getText();
        std::string temp = newTemp();
        code << "lw " << temp << ", " << var << "  # load " << var << "\n";
        return temp;
    }

    std::any visitMulDiv(CalcParser::MulDivContext *ctx) override {

        auto left = std::any_cast<std::string>(visit(ctx->expr(0)));
        auto right = std::any_cast<std::string>(visit(ctx->expr(1)));
        std::string temp = newTemp();

        if (ctx->op->getType() == CalcParser::MUL) {
            code << "mul " << temp << ", " << left << ", " << right << "\n";
        } else {
            code << "div " << temp << ", " << left << ", " << right << "\n";
        }

        return temp;
    }

    std::any visitAddSub(CalcParser::AddSubContext *ctx) override {
        auto left = std::any_cast<std::string>(visit(ctx->expr(0)));
        auto right = std::any_cast<std::string>(visit(ctx->expr(1)));
        std::string temp = newTemp();

        if (ctx->op->getType() == CalcParser::ADD) {
            code << "add " << temp << ", " << left << ", " << right << "\n";
        } else {
            code << "sub " << temp << ", " << left << ", " << right << "\n";
        }

        return temp;
    }

    std::string getCode() const { return code.str(); }
};

#endif
