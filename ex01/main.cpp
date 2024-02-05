#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        Bureaucrat alice("Alice", 149);

        bob.incrementGrade();   // =1
        alice.decrementGrade(); // =150

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        Form form1("Form1", 50, 75);
        Form form2("Form2", 1, 1);

        bob.signForm(form1);    // Devrait réussir
        alice.signForm(form2);  // Devrait échouer

        std::cout << form1 << std::endl; //automatique
        std::cout << form2 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}

