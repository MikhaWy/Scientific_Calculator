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
    std::cin >> command;

    if (command == 1){
        std::string expr, ans, hist;

            while(true){
                std::cout << "Enter an expression ('end' to terminate): " << std::endl;
                std::getline(std::cin, expr);
                if(expr.compare("end") == 0){
                    break;
                }

                ans = std::to_string(this->calculator.Evaluate(expr.c_str()));
                std::cout << ans << std::endl;
                
                hist = expr + " = " + ans;
                this->history_list->Append(hist);
            }

    }
    else if (command == 2){
        int indicator;
        
        std::cout << "Choose between: (1) Degree Mode or (2) Radian Mode: ";
        std::cin >> indicator;

        if(indicator == 1){
            this->calculator.SetMode(false);
        }
        else if(indicator == 2){
            this->calculator.SetMode(true);
        }
        else{
            std::cout << "Invalid input. Calculator is now set to Degree Mode" << std::endl;
            this->calculator.SetMode(false);
        }

    }
    else if (command == 3){
        this->history_list->PrintList();
    }
    else if (command == 4){
        this->history_list->Delete();
    }
    else if (command == 5){
        this->calculator.SetMode(false);
        this->calculator.answer = 0;
        this->history_list->Delete();
    }
    else if (command == 6){
        break;
    }
}

}