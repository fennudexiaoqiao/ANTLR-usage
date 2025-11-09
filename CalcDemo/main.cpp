#include <iostream>
#include <fstream>
#include "SemanticVisitor.h"
#include "TestObject.h"
#include "antlr4-runtime.h"
#include "anltr/CalcLexer.h"
#include "anltr/CalcParser.h"
#include "EvalVisitor.h"
#include "SemanticVisitor.h"
#include "CodeGenVisitor.h"

using namespace antlr4;

void runCalculator(const std::string& input) {
    ANTLRInputStream inputStream(input);
    CalcLexer lexer(&inputStream);
    CommonTokenStream tokens(&lexer);
    CalcParser parser(&tokens);

    // 构建语法树
    CalcParser::ProgContext* tree = parser.prog();

    // 1. 语义分析
    SemanticVisitor semanticChecker;
    semanticChecker.visitProg(tree);

    if (semanticChecker.hasErrors()) {
        std::cout << "Semantic errors found:\n";
        semanticChecker.printErrors();
        return;
    }

    std::cout << "Semantic analysis passed!\n\n";

    // 2. 表达式求值
    std::cout << "Evaluating expressions:\n";
    EvalVisitor evaluator;
    evaluator.visitProg(tree);

    std::cout << "\n";

    // 3. 代码生成
    // CodeGenVisitor codeGenerator;
    // codeGenerator.visitProg(tree);

    std::cout << "Generated MIPS code:\n";
    // std::cout << codeGenerator.getCode() << std::endl;
}

int main() {
    TestObject test;
    std::string testCode = R"(
x = 10
y = 20
z = (x + y) * 3
)";

    runCalculator(testCode);
    return 0;
}
