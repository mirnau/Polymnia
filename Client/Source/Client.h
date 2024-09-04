#pragma once

#include <iostream>
#include <Polymnia.h>
//#include "Log.h"

class Client : public Polymnia::Application
{
public:
    Client();
    ~Client();
 };

std::unique_ptr<Polymnia::Application> Polymnia::CreateApplication()
{
    return std::make_unique<Polymnia::Application>();
}