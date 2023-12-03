#include<iostream>
#include<string>
#include<cmath>
#include<sstream>
#include<stack>
#include<vector>


using namespace std;


// Token.h
class Token 
{
private:
    string value;

public:
    Token();
    Token(const string& val);

    string getValue() const;

    friend istream& operator>>(istream& console, Token& token);
    friend ostream& operator<<(ostream& console, const Token& token);
};


// Token.cpp
Token::Token() : value("") 
{

}

Token::Token(const string& val) : value(val) 
{

}

string Token::getValue() const 
{
    return value;
}

istream& operator>>(istream& console, Token& token) 
{
    console >> token.value;
    return console;
}

ostream& operator<<(ostream& console, const Token& token) 
{
    console<< token.value;
    return console;
}


// Expression.h
class Expression {
private:
    char* tokens;

public:
    Expression();
    Expression(const char* tokList);

    void addToken(const Token& token);
    double evaluate() const;

    friend istream& operator>>(istream& console, Expression& expr);
    friend ostream& operator<<(ostream& console, const Expression& expr);
};

// Expression.cpp
Expression::Expression()
{

}

Expression::Expression(const vector<Token>& tokList):tokens(tokList) 
{

}

void Expression::addToken(const Token& token) 
{
    tokens.push_back(token);
}

double Expression::evaluate() const
{
    stack<double> values;
    for (const auto& token : tokens) 
    {
        if (isdigit(token.getValue()[0]))
        {
            values.push(stod(token.getValue()));
        }
        else if (token.getValue() == "+") 
        {
            double operand2 = values.top();
            values.pop();
            double operand1 = values.top();
            values.pop();
            values.push(operand1 + operand2);
        }
        else if (token.getValue() == "-") 
        {
            double operand2 = values.top();
            values.pop();
            double operand1 = values.top();
            values.pop();
            values.push(operand1 - operand2);
        }
        else if (token.getValue() == "*") 
        {
            double operand2 = values.top();
            values.pop();
            double operand1 = values.top();
            values.pop();
            values.push(operand1 * operand2);
        }
        else if (token.getValue() == "/") 
        {
            double operand2 = values.top();
            values.pop();
            double operand1 = values.top();
            values.pop();
            if (operand2 != 0) 
            {
                values.push(operand1 / operand2);
            }
            else 
            {
                throw runtime_error("Împărțire la zero!");
            }
        }
    }

    if (!values.empty()) 
    {
        return values.top();
    }
    else 
    {
        throw runtime_error("Expresie invalidă!");
    }
}

istream& operator>>(istream& is, Expression& expr) 
{
    Token token;
    while (is >> token) 
    {
        expr.addToken(token);
    }
    return is;
}

ostream& operator<<(ostream& os, const Expression& expr) 
{
    for (const auto& token : expr.tokens)
    {
        os << token << " ";
    }
    return os;
}

// Calculator.h
class Calculator 
{
public:
    static double computeExpression(const std::string& expression);
    static void run();
};


double Calculator::computeExpression(const string& expression) 
{
    Expression expr;
    istringstream iss(expression);
    iss >> expr;
    return expr.evaluate();
}

void Calculator::run() 
{
    string input;
    while (true) 
    {
        cout << "Introduceti o ecuatie sau tastati 'exit' pentru a iesi: ";
        getline(cin, input);

        if (input == "exit") 
        {
            break;
        }

        try 
        {
            double result = computeExpression(input);
            cout << "Rezultat: " << result << endl;
        }
        catch (const exception& e) {
            cerr << "Eroare: " << e.what() << endl;
        }
    }
}



int main()
{
    Calculator::run();

    return 0;
}