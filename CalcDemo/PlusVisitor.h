#ifndef PLUSVISITOR_H
#define PLUSVISITOR_H

#include "anltr/tParserBaseVisitor.h"
class PlusVisitor : public tParserBaseVisitor
{
public:
    PlusVisitor();
    virtual std::any visitPlusItem(tParser::PlusItemContext *ctx) override {
        return visitChildren(ctx);
    }
};

#endif // PLUSVISITOR_H
