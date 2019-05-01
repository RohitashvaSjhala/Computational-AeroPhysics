			#include <iostream>
           #include <string>
           #include <fstream>
           #include <stdio.h>
           #include<iomanip>
           #include <math.h>
           #include <stdlib.h>
           #include "global_var.h"
           #include "Geometry.cpp"
           #include "CPmax_fun.cpp"
           #include "main_operations.cpp"
           #include "contour.cpp"
            #define pi 4*atan(1)
           using namespace std;
            
           int main()
           {
           	Geometry();
           	CPmax_fun();
           	main_operations();
		   	contour();
		   }
