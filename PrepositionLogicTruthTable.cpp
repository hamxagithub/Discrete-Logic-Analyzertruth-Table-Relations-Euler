//#include <iostream>
//#include <iomanip>
//#include <string>
//using namespace std;
//
//const int s = 26;
//
//bool is_alpha(char ch)
//{
//    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
//}
//
//string infix_to_postfix(const string& infix)
//{
//    char op_stack[s];
//    int top = -1;
//    string postfix;
//
//    for (int i = 0; i < infix.length(); ++i) {
//        char ch = infix[i];
//        switch (ch) {
//        case ' ':
//            break;
//        case '(':
//            op_stack[++top] = ch;
//            break;
//        case ')':
//            while (top >= 0 && op_stack[top] != '(') {
//                postfix += op_stack[top--];
//            }
//            if (top >= 0 && op_stack[top] == '(') {
//                top--;
//            }
//            break;
//        case '&':
//        case '|':
//        case '>':
//        case '=':
//            while (top >= 0 && op_stack[top] != '(' && op_stack[top] != '&' && op_stack[top] != '|' && op_stack[top] != '>')
//            {
//                postfix += op_stack[top--];
//            }
//            op_stack[++top] = ch;
//            break;
//        case '!':
//            op_stack[++top] = ch;
//            break;
//        default:
//            postfix += ch;
//            break;
//        }
//    }
//    while (top >= 0) {
//        postfix += op_stack[top--];
//    }
//
//    return postfix;
//}
//
//bool evaluate_postfix(const string& postfix, const char variables[s], const bool values[s]) {
//    bool eval_stack[s];
//    int top = -1;
//
//    for (int i = 0; i < postfix.length(); ++i) {
//        char ch = postfix[i];
//        switch (ch) {
//        case '&':
//        {
//            bool q = eval_stack[top--];
//            bool p = eval_stack[top--];
//            eval_stack[++top] = p && q;
//            break;
//        }
//        case '|':
//        {
//            bool q = eval_stack[top--];
//            bool p = eval_stack[top--];
//            eval_stack[++top] = p || q;
//            break;
//        }
//        case '>':
//        {
//            bool q = eval_stack[top--];
//            bool p = eval_stack[top--];
//            eval_stack[++top] = (p || !q);
//            break;
//        }
//        case '!':
//        {
//            bool p = eval_stack[top--];
//            eval_stack[++top] = !p;
//            break;
//        }
//        case '=':
//        {
//            bool q = eval_stack[top--];
//            bool p = eval_stack[top--];
//            eval_stack[++top] = (p && q) || (!p && !q);
//            break;
//        }
//        default:
//            for (int j = 0; j < s; ++j) {
//                if (variables[j] == ch) {
//                    eval_stack[++top] = values[j];
//                    break;
//                }
//            }
//            break;
//        }
//    }
//    return eval_stack[top];
//}
//
//void generate_variable_combinations(bool variable_combinations[s][s], const char variables[s], int& num_combinations)
//{
//    num_combinations = 1 << num_combinations;
//    for (int i = 0; i < num_combinations; ++i) {
//        for (int j = 0; j < s; ++j) {
//            variable_combinations[i][j] = (i & (1 << j)) != 0;
//        }
//    }
//}
//
//void extract_variables(const string& str, char variables[s], int& num_variables)
//{
//    num_variables = 0;
//
//    for (int i = 0; i < str.length(); ++i) {
//        char ch = str[i];
//        if (is_alpha(ch))
//        {
//            bool is_duplicate = false;
//            for (int j = 0; j < s; ++j) {
//                if (variables[j] == ch) {
//                    is_duplicate = true;
//                    break;
//                }
//            }
//            if (!is_duplicate)
//            {
//                variables[num_variables++] = ch;
//            }
//        }
//    }
//}
//
//void print_truth_table(const string& str, const char variables[s], const bool variable_combinations[s][s])
//{
//    char extracted_variables[s];
//    int num_extracted_variables = 0;
//    extract_variables(str, extracted_variables, num_extracted_variables);
//
//    for (int i = 0; i < num_extracted_variables; ++i) {
//        if (extracted_variables[i] != variables[i]) {
//            cerr << "Error: Mismatch in variables between expression and extracted variables." << endl;
//            return;
//        }
//    }
//
//    cout << "Truth Table" << endl;
//    cout << string(70, '-') << endl;
//    cout << setw(5) << " ";
//    for (int i = 0; i < num_extracted_variables; ++i) {
//        cout << setw(5) << extracted_variables[i];
//    }
//    for (int i = 0; i < 1; ++i) {
//        cout << setw(10) << " Expression ";
//    }
//
//    cout << endl;
//    cout << string(70, '-') << endl;
//
//    for (int i = 0; i < (1 << num_extracted_variables); ++i) {
//        cout << setw(5) << " ";
//        for (int j = num_extracted_variables - 1; j >= 0; --j)
//        {
//            cout << setw(5);
//            if (variable_combinations[i][j]) {
//                cout << "T";
//            }
//            else {
//                cout << "F";
//            }
//        }
//        bool value1 = evaluate_postfix(infix_to_postfix(str), variables, variable_combinations[i]);
//        cout << setw(10);
//        if (value1)
//        {
//            cout << "T";
//        }
//        else {
//            cout << "F";
//        }
//        cout << endl;
//    }
//    cout << string(70, '-') << endl;
//}
//
//int main()
//{
//    cout << "---------------**************Read the Instructions Carefully***************---------------" << endl;
//    cout << "1) Enter  for AND operator : '&'" << endl;
//    cout << "2) Enter  for OR operator  : '|'" << endl;
//    cout << "3) Enter  for NOT operator : '!'" << endl;
//    cout << "4) Enter  for Implication operatior : '>'" << endl;
//    cout << "5) Enter  for Biconditional operatior : '='" << endl;
//    string exp;
//    cout << "Please Enter  the  Expression : ";
//    getline(cin, exp);
//    char variables[s];
//    int num_variables = 0;
//    extract_variables(exp, variables, num_variables);
//    bool variable_combinations[s][s];
//    int num_combinations = num_variables;
//    generate_variable_combinations(variable_combinations, variables, num_combinations);
//    print_truth_table(exp, variables, variable_combinations);
//}
