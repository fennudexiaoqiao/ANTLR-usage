
// Generated from ./Calc.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CalcParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CalcParser.
 */
class  CalcListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(CalcParser::ProgContext *ctx) = 0;
  virtual void exitProg(CalcParser::ProgContext *ctx) = 0;

  virtual void enterPrintExpr(CalcParser::PrintExprContext *ctx) = 0;
  virtual void exitPrintExpr(CalcParser::PrintExprContext *ctx) = 0;

  virtual void enterAssign(CalcParser::AssignContext *ctx) = 0;
  virtual void exitAssign(CalcParser::AssignContext *ctx) = 0;

  virtual void enterBlank(CalcParser::BlankContext *ctx) = 0;
  virtual void exitBlank(CalcParser::BlankContext *ctx) = 0;

  virtual void enterParens(CalcParser::ParensContext *ctx) = 0;
  virtual void exitParens(CalcParser::ParensContext *ctx) = 0;

  virtual void enterMulDiv(CalcParser::MulDivContext *ctx) = 0;
  virtual void exitMulDiv(CalcParser::MulDivContext *ctx) = 0;

  virtual void enterAddSub(CalcParser::AddSubContext *ctx) = 0;
  virtual void exitAddSub(CalcParser::AddSubContext *ctx) = 0;

  virtual void enterId(CalcParser::IdContext *ctx) = 0;
  virtual void exitId(CalcParser::IdContext *ctx) = 0;

  virtual void enterInt(CalcParser::IntContext *ctx) = 0;
  virtual void exitInt(CalcParser::IntContext *ctx) = 0;


};

