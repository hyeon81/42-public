#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    this->target = "default";
    std::cout << "[ShrubberyCreationForm] is created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137)
{
    this->target = target;
    std::cout << "[ShrubberyCreationForm] "  << this->target << " is created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj): AForm(obj)
{
    std::cout << "[ShrubberyCreationForm] Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm:: operator=(const ShrubberyCreationForm &obj)
{
    std::cout << "[ShrubberyCreationForm] Copy assignment operator called" << std::endl;
    if (&obj != this)
    {
        this->target = obj.target;
    }
    return (*this);
}

ShrubberyCreationForm:: ~ShrubberyCreationForm()
{
    std::cout << "[ShrubberyCreationForm] " << this->target << " is destroyed" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::string asciiArt =
    "                                                      .\n"
    "                                              .         ;\n"
    "                 .              .              ;%     ;;\n"
    "                   ,           ,                :;%  %;\n"
    "                    :         ;                   :;%;'     .,\n"
    "           ,.        %;     %;            ;        %;'    ,;\n"
    "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
    "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
    "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
    "                `%;.     ;%;     %;'         `;%%;.%;'\n"
    "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
    "                    `:%;.  :;bd%;          %;@%;'\n"
    "                      `@%:.  :;%.         ;@@%;'   \n"
    "                        `@%.  `;@%.      ;@@%;         \n"
    "                          `@%%. `@%%    ;@@%;        \n"
    "                            ;@%. :@%%  %@@%;       \n"
    "                              %@bd%%%bd%%:;     \n"
    "                                #@%%%%%:;;\n"
    "                                %@@%%%::;\n"
    "                                %@@@%(o);  . '         \n"
    "                                %@@@o%;:(.,'         \n"
    "                            `.. %@@@o%::;         \n"
    "                               `)@@@o%::;         \n"
    "                                %@@(o)::;        \n"
    "                               .%@@@@%::;         \n"
    "                               ;%@@@@%%:;;;. \n"
    "                          ...;%@@@@@%%:;;;;,..\n";

    try 
    {
        if (executor.getGrade() > this->getExecGrade())
            throw GradeTooLowException();
        
        std::string newFile(target);
        newFile.append("_shrubbery");
        std::ofstream ofs;
        ofs.open(newFile.c_str());

        if (!ofs.is_open())
            throw FileOpenFailedException();
        ofs << asciiArt;
        ofs.close();
    } catch (std::exception & e)
    {
        std::cerr << "[ShrubberyCreationForm] " << e.what() << std::endl;
        throw;
    }
}