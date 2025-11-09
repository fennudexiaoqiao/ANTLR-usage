
// Generated from ./Calc.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CalcVisitor.h"


/**
 * This class provides an empty implementation of CalcVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  CalcBaseVisitor : public CalcVisitor {
public:

  virtual std::any visitProg(CalcParser::ProgContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPrintExpr(CalcParser::PrintExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign(CalcParser::AssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlank(CalcParser::BlankContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParens(CalcParser::ParensContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulDiv(CalcParser::MulDivContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSub(CalcParser::AddSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitId(CalcParser::IdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInt(CalcParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }


};

