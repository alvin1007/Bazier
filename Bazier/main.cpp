#include "main.h"
#include "System.h"

int main(int argc, char* argv[])
{
	System* Main = new System;

	Main->Init();
	Main->Run();
	Main->Clear();

	return 0;
}