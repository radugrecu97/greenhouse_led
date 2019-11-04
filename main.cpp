/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: radu
 *
 * Created on November 4, 2019, 1:23 PM
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

void set_light(unsigned int intensity)
{
    std::fstream fs;
    
    fs.open("/sys/class/pwm/pwmchip1/pwm-1:1/period");
    fs << "20000000";
    fs.close();
    
    fs.open("/sys/class/pwm/pwmchip1/pwm-1:1/duty_cycle");
    fs << to_string((int) (20000000 * (intensity/100.0)));
    fs.close();
    
    fs.open("/sys/class/pwm/pwmchip1/pwm-1:1/enable");
    fs << "1";
    fs.close();
}

int main(int argc, char *argv[]){

    // Parameter count check
    if ((argc != 2))
    {
        cout << "Usage:" << argv[0] << " [light_intensity]\r\n";
        cout << "light_intensity ranges from 0 to 100\r\n";
        return -1;
    }

    // Parameter value check
    int light_intensity = atoi(argv[1]);

    if (((light_intensity < 0) || light_intensity > 100))
        cout << "Invalid light intensity. Enter value from 0 to 100\r\n";
    
    char config[10];
    FILE *fp;
    
    // configure port to PWM
    fp = popen("config-pin -q P9_21", "r");
    fscanf(fp, "%*s %*s %s", config);
    fclose(fp);
    
    if (std::strcmp(config, "pwm"))
    {
        system("config-pin -a P9_21 pwm");
    }
    
    // configure PWM channel
    std::fstream fs;
    fs.open("/sys/class/pwm/pwmchip1/export");
    fs << "1";
    fs.close();
    
    set_light(light_intensity);
            
    return 0;
}