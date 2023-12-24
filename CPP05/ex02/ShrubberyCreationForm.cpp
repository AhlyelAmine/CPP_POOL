#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) 
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm) : AForm(shrubberyCreationForm.getName(), shrubberyCreationForm.getGradeToSign(), shrubberyCreationForm.getGradeToExecute())
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberyCreationForm)
{
    // this->name = shrubberyCreationForm.name;
    (void)shrubberyCreationForm;
    return (*this);
}

bool    ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (this->getGradeToExecute() < executor.getGrade())
        return (throw (AForm::GradeTooLowException()), false);
    else if (!this->getIsSigned())
    {
        std::cerr << "ShrubberyCreationForm couldn't be executed by " << executor.getName() << " because form it wasn't signed!" << std::endl;
        return (false);
    }
    std::string name = executor.getName().append("_shrubbery");
    std::ofstream out;
    out.open(name.c_str());
    if (!out.is_open())
        return (false);

    out     <<"              _{\\ _{\\{\\/}/}/}__\n"
            <<"             {/{/\\}{/{/\\}(\\}{/\\} _\n"
            <<"            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
            <<"         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
            <<"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
            <<"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
            <<"      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
            <<"      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n"
            <<"     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
            <<"      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n"
            <<"       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
            <<"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n"
            <<"       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n"
            <<"         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
            <<"          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n"
            <<"            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n"
            <<"             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
            <<"              {){/ {\\/}{\\/} \\}\\}\n"
            <<"              (_)  \\.-\'.-/\n"
            <<"          __...--- |'-.-'| --...__\n"
            <<"   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
            <<" -\"    ' .  . '    |.'-._| '  . .  '   \n"
            <<" .  '-  '    .--'  | '-.'|    .  '  . '\n"
            <<"          ' ..     |'-_.-|\n"
            <<"  .  '  .       _.-|-._ -|-._  .  '  .\n"
            <<"              .'   |'- .-|   '.\n"
            <<"  ..-'   ' .  '.   `-._.-`   .'  '  - .\n"
            <<"   .-' '        '-._______.-'     '  .\n"
            <<"        .      ~,\n"
            <<"    .       .   |\\   .    ' '-.\n";
    return (true);
}
