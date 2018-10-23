#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "args.hxx"

using namespace std;

#include "logos.hxx"

int ParseArguments(int argc, char **argv) {
    args::ArgumentParser parser("Welcome to the OpenIOT CLI. Visit our website at https://www.openiot.com for great DIY projects, hackathons and many resources");
    args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
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
    return 0;
}

int main(int argc, char **argv)
{
    /* generate logo  */
    srand (time(NULL));
    int iLogo = rand() % 12;
    cout << logos[iLogo] << endl;
    if( ParseArguments(argc, argv) )
        cout << "Hello world!" << endl;
    return 0;
}
