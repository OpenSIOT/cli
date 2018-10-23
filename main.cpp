#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "args.hxx"

using namespace std;

#include "logos.hxx"

int ParseArguments(int argc, char **argv) {

    args::ArgumentParser parser("Welcome to the OpenIOT CLI. Visit our website at https://www.openiot.com for great DIY projects, hackathons and many resources");

    args::Group group(parser, "CLI Info flags:", args::Group::Validators::Xor);
    args::Flag version(group, "version", "The OpenIOT version for the current project", {'v'});
    args::HelpFlag help(group, "help", "Display this help menu", {'h', "help"});

    args::Group commands(parser, "commands");
    args::Command add(commands, "add", "adds a new hardware component to the project");
    args::Command new_project(commands, "new", "scaffolds a new OpenIOT project");

    args::CompletionFlag completion(parser, {"complete"});

    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (const args::Completion& e)
    {
        std::cout << e.what();
        return 0;
    }
    catch (const args::Help&)
    {
        std::cout << parser;
        return 0;
    }
    catch (const args::ParseError& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
        return 1;
    }
    if (version) { std::cout << "OpenIOT 1.0.0 (cli). (built: October 23 2018) \nCopyright (c) 2018,  The OpenIOT Community " << std::endl; }
    return 0;
}

int main(int argc, char **argv)
{

    /* generate logo  */
    srand (time(NULL));
    int iLogo = rand() % 12;
    cout << endl << endl << logos[iLogo] << endl;

    return ParseArguments(argc, argv);

}
