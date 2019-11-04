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

int main(){
//   std::fstream fs;
//
//   fs.open("/sys/kernel/debug/omap_mux/gpmc_ad4");
//   fs << "7";
//   fs.close();
//   fs.open("/sys/class/gpio/export");
//   fs << "32";
//   fs.close();
//   fs.open("/sys/class/gpio/gpio32/direction");
//   fs << "out";
//   fs.close();
//   fs.open("/sys/class/gpio/gpio32/value");
//   fs << "1"; // "0" for off
//   fs.close();
   // select whether it is on, off or flash
    
   FILE *fp;
   
   fp = popen("uname -a", "r");
   char buffer [100];
   
    fscanf(fp,....);

//   if (fp == NULL) perror ("Error opening file");
//   else
//   {
//     while ( ! feof (fp) )
//     {
//       if ( fgets (buffer , 100 , fp) == NULL ) break;
//       fputs (buffer , stdout);
//     }
//     fclose (fp);
//   }

   return 0;
}