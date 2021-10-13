#include "../includes/program.h"

void Program::Init(){
    std::cout << "List of Commands:" << std::endl;
    std::cout << "[1] Calculate" << std::endl;
    std::cout << "[2] Degree Mode" << std::endl;
    std::cout << "[3] View History" << std::endl;
    std::cout << "[4] Delete History" << std::endl;
    std::cout << "[5] Reset Calculator" << std::endl;
    std::cout << "[6] Exit Program" << std::endl << std::endl;

    int command;
    while(true){
        std::cout << "Enter a Command: " << std::endl;
        std::cin >> command;
        std::cin.ignore();
        std::cout << "----------------------------------" << std::endl;

        if (command == 1){
            std::string expr, ans, hist;

            std::cout << "Enter an expression ('end' to terminate): " << std::endl;
            
            while(true){
                //std::cout << "= ";
                std::getline(std::cin, expr);

                if (expr.compare("end") == 0) {
                    std::cout << "----------------------------------" << std::endl;
                    break;
                }
                
                ans = std::to_string(this->calculator.Evaluate(expr.c_str()));
                std::cout << "= " << ans << std::endl;
                std::cout << "----------------------------------" << std::endl;
            
                hist = "> " + expr + " = " + ans;
                this->history_list->Append(hist);
            }
        }
        else if (command == 2){
            int indicator;
        
            std::cout << "Choose between: (1) Degree Mode or (2) Radian Mode: ";
            std::cin >> indicator;

            if(indicator == 1){
                this->calculator.SetMode(false);
                std::cout << "SUCCESS: Calculator is now set to Degree Mode." << std::endl;
                std::cout << "----------------------------------" << std::endl;
            }
            else if(indicator == 2){
                this->calculator.SetMode(true);
                std::cout << "SUCCESS: Calculator is now set to Radian Mode." << std::endl;
                std::cout << "----------------------------------" << std::endl;
            }
            else{
                std::cout << "WARNING: Invalid input. Calculator is now set to Degree Mode." << std::endl;
                std::cout << "----------------------------------" << std::endl;
                this->calculator.SetMode(false);
            }

        }
        else if (command == 3){
            std::cout << "Calculator history: " << std::endl;
            this->history_list->PrintList();
            std::cout << "----------------------------------" << std::endl;
        }
        else if (command == 4){
            this->history_list->Delete();
            std::cout << "History deleted." << std::endl;
            std::cout << "----------------------------------" << std::endl;
        }
        else if (command == 5){
            this->calculator.SetMode(false);
            this->calculator.answer = 0;
            this->history_list->Delete();
            std::cout << "SUCCESS: Calculator has been reset." << std::endl;
            std::cout << "----------------------------------" << std::endl;
        }
        else if (command == 6){
            break;
        }
        else {
            std::cout << "WARNING: Invalid command. Enter another command." << std::endl;
            continue;
        }
    }
}