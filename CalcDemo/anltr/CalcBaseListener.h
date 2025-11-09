
// Generated from ./Calc.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CalcListener.h"


/**
 * This class provides an empty implementation of CalcListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  CalcBaseListener : public CalcListener {
public:

  virtual void enterProg(CalcParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(CalcParser::ProgContext * /*ctx*/) override { }

  virtual void enterPrintExpr(CalcParser::PrintExprContext * /*ctx*/) override { }
  virtual void exitPrintExpr(CalcParser::PrintExprContext * /*ctx*/) override { }

  virtual void enterAssign(CalcParser::AssignContext * /*ctx*/) override { }
  virtual void exitAssign(CalcParser::AssignContext * /*ctx*/) override { }

  virtual void enterBlank(CalcParser::BlankContext * /*ctx*/) override { }
  virtual void exitBlank(CalcParser::BlankContext * /*ctx*/) override { }

  virtual void enterParens(CalcParser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(CalcParser::ParensContext * /*ctx*/) override { }

  virtual void enterMulDiv(CalcParser::MulDivContext * /*ctx*/) override { }
  virtual void exitMulDiv(CalcParser::MulDivContext * /*ctx*/) override { }

  virtual void enterAddSub(CalcParser::AddSubContext * /*ctx*/) override { }
  virtual void exitAddSub(CalcParser::AddSubContext * /*ctx*/) override { }

  virtual void enterId(CalcParser::IdContext * /*ctx*/) override { }
  virtual void exitId(CalcParser::IdContext * /*ctx*/) override { }

  virtual void enterInt(CalcParser::IntContext * /*ctx*/) override { }
  virtual void exitInt(CalcParser::IntContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

