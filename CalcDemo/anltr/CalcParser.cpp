
// Generated from ./Calc.g4 by ANTLR 4.13.2


#include "CalcListener.h"
#include "CalcVisitor.h"

#include "CalcParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CalcParserStaticData final {
  CalcParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CalcParserStaticData(const CalcParserStaticData&) = delete;
  CalcParserStaticData(CalcParserStaticData&&) = delete;
  CalcParserStaticData& operator=(const CalcParserStaticData&) = delete;
  CalcParserStaticData& operator=(CalcParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag calcParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CalcParserStaticData> calcParserStaticData = nullptr;

void calcParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (calcParserStaticData != nullptr) {
    return;
  }
#else
  assert(calcParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CalcParserStaticData>(
    std::vector<std::string>{
      "prog", "stat", "expr"
    },
    std::vector<std::string>{
      "", "'='", "'('", "')'", "'*'", "'/'", "'+'", "'-'"
    },
    std::vector<std::string>{
      "", "", "", "", "MUL", "DIV", "ADD", "SUB", "ID", "INT", "NEWLINE", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,11,45,2,0,7,0,2,1,7,1,2,2,7,2,1,0,4,0,8,8,0,11,0,12,0,9,1,0,1,0,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,23,8,1,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,3,2,32,8,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,40,8,2,10,2,12,2,43,9,2,1,
  	2,0,1,4,3,0,2,4,0,2,1,0,4,5,1,0,6,7,48,0,7,1,0,0,0,2,22,1,0,0,0,4,31,
  	1,0,0,0,6,8,3,2,1,0,7,6,1,0,0,0,8,9,1,0,0,0,9,7,1,0,0,0,9,10,1,0,0,0,
  	10,11,1,0,0,0,11,12,5,0,0,1,12,1,1,0,0,0,13,14,3,4,2,0,14,15,5,10,0,0,
  	15,23,1,0,0,0,16,17,5,8,0,0,17,18,5,1,0,0,18,19,3,4,2,0,19,20,5,10,0,
  	0,20,23,1,0,0,0,21,23,5,10,0,0,22,13,1,0,0,0,22,16,1,0,0,0,22,21,1,0,
  	0,0,23,3,1,0,0,0,24,25,6,2,-1,0,25,32,5,9,0,0,26,32,5,8,0,0,27,28,5,2,
  	0,0,28,29,3,4,2,0,29,30,5,3,0,0,30,32,1,0,0,0,31,24,1,0,0,0,31,26,1,0,
  	0,0,31,27,1,0,0,0,32,41,1,0,0,0,33,34,10,5,0,0,34,35,7,0,0,0,35,40,3,
  	4,2,6,36,37,10,4,0,0,37,38,7,1,0,0,38,40,3,4,2,5,39,33,1,0,0,0,39,36,
  	1,0,0,0,40,43,1,0,0,0,41,39,1,0,0,0,41,42,1,0,0,0,42,5,1,0,0,0,43,41,
  	1,0,0,0,5,9,22,31,39,41
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  calcParserStaticData = std::move(staticData);
}

}

CalcParser::CalcParser(TokenStream *input) : CalcParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

CalcParser::CalcParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  CalcParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *calcParserStaticData->atn, calcParserStaticData->decisionToDFA, calcParserStaticData->sharedContextCache, options);
}

CalcParser::~CalcParser() {
  delete _interpreter;
}

const atn::ATN& CalcParser::getATN() const {
  return *calcParserStaticData->atn;
}

std::string CalcParser::getGrammarFileName() const {
  return "Calc.g4";
}

const std::vector<std::string>& CalcParser::getRuleNames() const {
  return calcParserStaticData->ruleNames;
}

const dfa::Vocabulary& CalcParser::getVocabulary() const {
  return calcParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView CalcParser::getSerializedATN() const {
  return calcParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

CalcParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* CalcParser::ProgContext::EOF() {
  return getToken(CalcParser::EOF, 0);
}

std::vector<CalcParser::StatContext *> CalcParser::ProgContext::stat() {
  return getRuleContexts<CalcParser::StatContext>();
}

CalcParser::StatContext* CalcParser::ProgContext::stat(size_t i) {
  return getRuleContext<CalcParser::StatContext>(i);
}


size_t CalcParser::ProgContext::getRuleIndex() const {
  return CalcParser::RuleProg;
}

void CalcParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void CalcParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}


std::any CalcParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

CalcParser::ProgContext* CalcParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, CalcParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(7); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(6);
      stat();
      setState(9); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1796) != 0));
    setState(11);
    match(CalcParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

CalcParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcParser::StatContext::getRuleIndex() const {
  return CalcParser::RuleStat;
}

void CalcParser::StatContext::copyFrom(StatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- BlankContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::BlankContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::BlankContext::BlankContext(StatContext *ctx) { copyFrom(ctx); }

void CalcParser::BlankContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlank(this);
}
void CalcParser::BlankContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlank(this);
}

std::any CalcParser::BlankContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitBlank(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintExprContext ------------------------------------------------------------------

CalcParser::ExprContext* CalcParser::PrintExprContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::PrintExprContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::PrintExprContext::PrintExprContext(StatContext *ctx) { copyFrom(ctx); }

void CalcParser::PrintExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrintExpr(this);
}
void CalcParser::PrintExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrintExpr(this);
}

std::any CalcParser::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::AssignContext::ID() {
  return getToken(CalcParser::ID, 0);
}

CalcParser::ExprContext* CalcParser::AssignContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

tree::TerminalNode* CalcParser::AssignContext::NEWLINE() {
  return getToken(CalcParser::NEWLINE, 0);
}

CalcParser::AssignContext::AssignContext(StatContext *ctx) { copyFrom(ctx); }

void CalcParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}
void CalcParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}

std::any CalcParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
CalcParser::StatContext* CalcParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 2, CalcParser::RuleStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(22);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<CalcParser::PrintExprContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(13);
      expr(0);
      setState(14);
      match(CalcParser::NEWLINE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<CalcParser::AssignContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(16);
      match(CalcParser::ID);
      setState(17);
      match(CalcParser::T__0);
      setState(18);
      expr(0);
      setState(19);
      match(CalcParser::NEWLINE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CalcParser::BlankContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(21);
      match(CalcParser::NEWLINE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

CalcParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t CalcParser::ExprContext::getRuleIndex() const {
  return CalcParser::RuleExpr;
}

void CalcParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParensContext ------------------------------------------------------------------

CalcParser::ExprContext* CalcParser::ParensContext::expr() {
  return getRuleContext<CalcParser::ExprContext>(0);
}

CalcParser::ParensContext::ParensContext(ExprContext *ctx) { copyFrom(ctx); }

void CalcParser::ParensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParens(this);
}
void CalcParser::ParensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParens(this);
}

std::any CalcParser::ParensContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitParens(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::MulDivContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::MulDivContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::MulDivContext::MUL() {
  return getToken(CalcParser::MUL, 0);
}

tree::TerminalNode* CalcParser::MulDivContext::DIV() {
  return getToken(CalcParser::DIV, 0);
}

CalcParser::MulDivContext::MulDivContext(ExprContext *ctx) { copyFrom(ctx); }

void CalcParser::MulDivContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDiv(this);
}
void CalcParser::MulDivContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDiv(this);
}

std::any CalcParser::MulDivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitMulDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubContext ------------------------------------------------------------------

std::vector<CalcParser::ExprContext *> CalcParser::AddSubContext::expr() {
  return getRuleContexts<CalcParser::ExprContext>();
}

CalcParser::ExprContext* CalcParser::AddSubContext::expr(size_t i) {
  return getRuleContext<CalcParser::ExprContext>(i);
}

tree::TerminalNode* CalcParser::AddSubContext::ADD() {
  return getToken(CalcParser::ADD, 0);
}

tree::TerminalNode* CalcParser::AddSubContext::SUB() {
  return getToken(CalcParser::SUB, 0);
}

CalcParser::AddSubContext::AddSubContext(ExprContext *ctx) { copyFrom(ctx); }

void CalcParser::AddSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddSub(this);
}
void CalcParser::AddSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddSub(this);
}

std::any CalcParser::AddSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitAddSub(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::IdContext::ID() {
  return getToken(CalcParser::ID, 0);
}

CalcParser::IdContext::IdContext(ExprContext *ctx) { copyFrom(ctx); }

void CalcParser::IdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterId(this);
}
void CalcParser::IdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitId(this);
}

std::any CalcParser::IdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitId(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntContext ------------------------------------------------------------------

tree::TerminalNode* CalcParser::IntContext::INT() {
  return getToken(CalcParser::INT, 0);
}

CalcParser::IntContext::IntContext(ExprContext *ctx) { copyFrom(ctx); }

void CalcParser::IntContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt(this);
}
void CalcParser::IntContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<CalcListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt(this);
}

std::any CalcParser::IntContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<CalcVisitor*>(visitor))
    return parserVisitor->visitInt(this);
  else
    return visitor->visitChildren(this);
}

CalcParser::ExprContext* CalcParser::expr() {
   return expr(0);
}

CalcParser::ExprContext* CalcParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  CalcParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  CalcParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, CalcParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(31);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case CalcParser::INT: {
        _localctx = _tracker.createInstance<IntContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(25);
        match(CalcParser::INT);
        break;
      }

      case CalcParser::ID: {
        _localctx = _tracker.createInstance<IdContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(26);
        match(CalcParser::ID);
        break;
      }

      case CalcParser::T__1: {
        _localctx = _tracker.createInstance<ParensContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(27);
        match(CalcParser::T__1);
        setState(28);
        expr(0);
        setState(29);
        match(CalcParser::T__2);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(41);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(39);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(33);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(34);
          antlrcpp::downCast<MulDivContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CalcParser::MUL

          || _la == CalcParser::DIV)) {
            antlrcpp::downCast<MulDivContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(35);
          expr(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(36);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(37);
          antlrcpp::downCast<AddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == CalcParser::ADD

          || _la == CalcParser::SUB)) {
            antlrcpp::downCast<AddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(38);
          expr(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(43);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool CalcParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool CalcParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

void CalcParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  calcParserInitialize();
#else
  ::antlr4::internal::call_once(calcParserOnceFlag, calcParserInitialize);
#endif
}
