
void contour()
{
	long double const1,const2,const3,const4;
		output.open("contour_file.dat");
		input.open("nodes.txt");
		output<<"ZONE I="<<number_of_nodes<<" "<<"J="<<line_counter<<" "<<"F=FEPOINT ET=QUADRILATERAL"<<endl;
	for(i=1;i<=number_of_nodes;i++)
		{
			input>>const1>>const2>>const3;
			input3.open("cells.txt");
			if(input3.is_open())
			{
				
	long double	pr=0.000000000000;
			int	temp2=0;
				for(j=0;j<line_counter;j++)
				{
					input3>>n1>>n2>>n3;
					if(i==n1||i==n2||i==n3)
					{
						temp2++;
						pr=pr+p[j];
					}
				}
				input3.close();
				if(temp2!=0)
				{
					output<<const1<<"  "<<const2<<"  "<<const3<<"  "<<pr/temp2<<endl;
				}
				else
				{
					output<<const1<<"  "<<const2<<"  "<<const3<<"  "<<"0.000000000000"<<endl;
				}
			}
			else
			{
				cout<<"File not Found!"<<endl;
			}
		}
		input.close();
		
		input.open("cells.txt");
		for(i=0;i<line_counter;i++)
		{
			setprecision(0);
			input>>const1>>const2>>const3;
			output<<const1<<"  "<<const2<<"  "<<const3<<"  "<<const3<<endl;
		}
		output.close();
		input.close();
}

