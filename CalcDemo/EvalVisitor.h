#ifndef EVALVISITOR_H
#define EVALVISITOR_H

#include "anltr/CalcBaseVisitor.h"
#include <unordered_map>
#include <stdexcept>
/**
 * @brief The EvalVisitor class
 * 表达式求值 Visitor (EvalVisitor.h)
 */
class EvalVisitor : public CalcBaseVisitor {
private:
    std::unordered_map<std::string, int> memory;

public:
    // 访问赋值语句
    std::any visitAssign(CalcParser::AssignContext *ctx) override {
        std::string id = ctx->ID()->getText();
        int value = std::any_cast<int>(visit(ctx->expr()));
        memory[id] = value;

        return value;
    }

    // 访问打印表达式
    std::any visitPrintExpr(CalcParser::PrintExprContext *ctx) override {
        int value = std::any_cast<int>(visit(ctx->expr()));
        std::cout << value << std::endl;
        return value;
    }

    // 访问整数
    std::any visitInt(CalcParser::IntContext *ctx) override {
        return std::stoi(ctx->INT()->getText());
    }

    // 访问变量
    std::any visitId(CalcParser::IdContext *ctx) override {
        std::string id = ctx->ID()->getText();
        if (memory.find(id) != memory.end()) {
            return memory[id];
        }
        throw std::runtime_error("Unknown variable: " + id);
    }

    // 访问乘除运算
    std::any visitMulDiv(CalcParser::MulDivContext *ctx) override {
        int left = std::any_cast<int>(visit(ctx->expr(0)));
        int right = std::any_cast<int>(visit(ctx->expr(1)));

        if (ctx->op->getType() == CalcParser::MUL) {
            return left * right;
        } else {
            if (right == 0) throw std::runtime_error("Division by zero");
            return left / right;
        }
    }

    // 访问加减运算
    std::any visitAddSub(CalcParser::AddSubContext *ctx) override {
        int left = std::any_cast<int>(visit(ctx->expr(0)));
        int right = std::any_cast<int>(visit(ctx->expr(1)));

        if (ctx->op->getType() == CalcParser::ADD) {
            return left + right;
        } else {
            return left - right;
        }
    }

    // 访问括号表达式
    std::any visitParens(CalcParser::ParensContext *ctx) override {
        return visit(ctx->expr());
    }

    // 访问空白行
    std::any visitBlank(CalcParser::BlankContext *ctx) override {
        return 0;
    }
};

#endif
