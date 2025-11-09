#ifndef SEMANTICVISITOR_H
#define SEMANTICVISITOR_H

#include "anltr/CalcBaseVisitor.h"
#include <unordered_set>
#include <vector>
#include <iostream>
/**
 * @brief The SemanticError class
 * 语义分析 Visitor (SemanticVisitor.h)
 */
class SemanticError {
public:
    std::string message;
    size_t line;
    size_t charPos;

    SemanticError(const std::string& msg, size_t ln, size_t pos)
        : message(msg), line(ln), charPos(pos) {}
};

class SemanticVisitor : public CalcBaseVisitor {
private:
    std::unordered_set<std::string> declaredVars;
    std::vector<SemanticError> errors;

    void addError(antlr4::ParserRuleContext* ctx, const std::string& msg) {
        size_t line = ctx->getStart()->getLine();
        size_t pos = ctx->getStart()->getCharPositionInLine();
        errors.emplace_back(msg, line, pos);
    }

public:
    // 访问程序入口
    std::any visitProg(CalcParser::ProgContext *ctx) override {
        declaredVars.clear();
        errors.clear();

        // 访问所有语句
        for (auto stat : ctx->stat()) {
            visit(stat);
        }

        return nullptr;
    }

    // 访问赋值语句
    std::any visitAssign(CalcParser::AssignContext *ctx) override {
        std::string varName = ctx->ID()->getText();

        // 检查变量是否已声明
        if (declaredVars.find(varName) == declaredVars.end()) {
            declaredVars.insert(varName);
        }

        // 分析表达式
        visit(ctx->expr());
        return nullptr;
    }

    // 访问表达式语句
    std::any visitPrintExpr(CalcParser::PrintExprContext *ctx) override {
        return visit(ctx->expr());
    }

    // 访问标识符
    std::any visitId(CalcParser::IdContext *ctx) override {
        std::string varName = ctx->ID()->getText();

        if (declaredVars.find(varName) == declaredVars.end()) {
            addError(ctx, "Undeclared variable: " + varName);
        }

        return nullptr;
    }

    // 访问整数
    std::any visitInt(CalcParser::IntContext *ctx) override {
        try {
            int value = std::stoi(ctx->INT()->getText());
            // 可以添加范围检查等语义规则
        } catch (const std::out_of_range&) {
            addError(ctx, "Integer value out of range");
        }
        return nullptr;
    }

    // 访问二元运算
    std::any visitMulDiv(CalcParser::MulDivContext *ctx) override {
        visit(ctx->expr(0));
        visit(ctx->expr(1));

        // 检查除以零
        if (ctx->op->getType() == CalcParser::DIV) {
            auto right = ctx->expr(1);
            if (auto intCtx = dynamic_cast<CalcParser::IntContext*>(right)) {
                if (std::stoi(intCtx->INT()->getText()) == 0) {
                    addError(ctx, "Division by zero");
                }
            }
        }

        return nullptr;
    }

    std::any visitAddSub(CalcParser::AddSubContext *ctx) override {
        visit(ctx->expr(0));
        visit(ctx->expr(1));
        return nullptr;
    }

    bool hasErrors() const { return !errors.empty(); }

    void printErrors() const {
        for (const auto& error : errors) {
            std::cerr << "Error at line " << error.line
                      << ":" << error.charPos
                      << " - " << error.message << std::endl;
        }
    }
};

#endif
