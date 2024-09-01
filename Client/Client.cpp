#include <iostream>
#include <Polymnia.h>

class Client : public Polymnia::Application
{
public:
    Client()
    {

    }
    ~Client()
    {
    
    }
 };

Polymnia::Application* Polymnia::CreateApplication()
{
    return new Client();
}