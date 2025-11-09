
// Generated from ./Calc.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "CalcParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CalcParser.
 */
class  CalcVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CalcParser.
   */
    virtual std::any visitProg(CalcParser::ProgContext *context) = 0;

    virtual std::any visitPrintExpr(CalcParser::PrintExprContext *context) = 0;

    virtual std::any visitAssign(CalcParser::AssignContext *context) = 0;

    virtual std::any visitBlank(CalcParser::BlankContext *context) = 0;

    virtual std::any visitParens(CalcParser::ParensContext *context) = 0;

    virtual std::any visitMulDiv(CalcParser::MulDivContext *context) = 0;

    virtual std::any visitAddSub(CalcParser::AddSubContext *context) = 0;

    virtual std::any visitId(CalcParser::IdContext *context) = 0;

    virtual std::any visitInt(CalcParser::IntContext *context) = 0;


};

