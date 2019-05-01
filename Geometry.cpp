void Geometry()
{
		input.open("nose1.txt");
		if(input.is_open())
		// Start calcualting no. of nodes
		{
			while(getline(input,line))
			{
				line_counter++;
			 	pos = line.find("$Nodes");
			  	if(pos!=string::npos) // string::npos is returned if string is not found
        			{
        				input>>number_of_nodes;
            			//cout <<"node Found!"<<endl;
            			cout<<"number_of_nodes="<<number_of_nodes<<endl;
						cout<<"line_counter="<<line_counter<<endl;
            			break;
        			}
			}
			//end calculating no. of nodes
			//start calculating no. of elements and triangles
			while(getline(input,line))
			{
				line_counter++;
			 	pos = line.find("$Elements");
			  	if(pos!=string::npos) // string::npos is returned if string is not found
        			{
        				input>>number_of_elements;
            			cout<<"number_of_elements="<<number_of_elements<<endl;
						cout<<"line_counter="<<line_counter<<endl;
						line_counter=0;
						for(i=1;i<=number_of_elements;i++)
						{
							input>>dummy>>a;
							if(a==15)
							{
								input>>dummy>>dummy>>dummy>>dummy;
							}
							else if(a==1)
							{
								input>>dummy>>dummy>>dummy>>dummy>>dummy;
							}
							else
							{
								line_counter++;
								input>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy;
							}
						}
						cout<<"number_of_triangles="<<line_counter<<endl;
						break;
        			}
			}
			input.close();
		}
	
		else
		{
			cout<<"File not found!"<<endl;
		}
					//end calculating no. of elements and triangles
	
	

	input.open("nose1.txt");
		if(input.is_open())
		{
			while(getline(input,line))
			{
			 	pos = line.find("$Nodes");
			  	if(pos!=string::npos) // string::npos is returned if string is not found
        			{
        				//starts storing nodes and calculating centroid of whole body
        				input>>dummy;
        				q=(long double *)malloc(sizeof(long double)*3*(number_of_nodes));
        				for(i=0;i<(3*number_of_nodes);i=i+3)
        				{
        					input>>dummy>>q[i]>>q[i+1]>>q[i+2];
        					x_node=x_node + q[i];
        					y_node=y_node + q[i+1];
        					z_node=z_node + q[i+2];
						}
					//	cout<<(x_node/number_of_nodes)<<endl;
					//	cout<<(y_node/number_of_nodes)<<endl;
					//	cout<<(z_node/number_of_nodes)<<endl;
        			}
			}
		}			//ends storing nodes and calculating centroid of whole body
		input.close();
		input.open("nose1.txt");
		if(input.is_open())
		{
			while(getline(input,line))
			{
				pos = line.find("$Elements");
				if(pos!=string::npos)
				{		///starts storing cells
					input>>dummy;
					cells=(long double *)malloc(sizeof(long double)*3*line_counter);
					for(i=0;i<(number_of_elements-line_counter);i++)
						{
							input>>dummy>>a;
							if(a==15)
							{
								input>>dummy>>dummy>>dummy>>dummy;
							}
							else if(a==1)
							{
								input>>dummy>>dummy>>dummy>>dummy>>dummy;
							}
							else
							{
								cout<<"Neither 15 nor 1"<<endl;
							}
						}
						for(i=0;i<3*line_counter;i=i+3)
						{
							input>>dummy>>dummy>>dummy>>dummy>>dummy>>cells[i]>>cells[i+1]>>cells[i+2];
						}
				}		//ends storing cells
			}
			input.close();
			
			output.open("nodes.txt");
			output<<setprecision(12)<<fixed;
			for(i=0;i<(3*number_of_nodes);i=i+3)
        		{
        			output<<q[i]<<" "<<q[i+1]<<" "<<q[i+2]<<endl;		//stores nodes in text file
				}
			output.close();
			
			output.open("cells.txt");
			output<<setprecision(0)<<fixed;
			for(i=0;i<3*line_counter;i=i+3)
			{
				output<<cells[i]<<" "<<cells[i+1]<<" "<<cells[i+2]<<endl;	//stores cells in text file
			}
			output.close();	
		}
		else
		{
			cout<<"File not found!"<<endl;
		}

	

/*	input.open("nose1.txt");
		if(input.is_open())
		{
			while(getline(input,line))
			{
			 	pos = line.find("$Elements");
			  	if(pos!=string::npos) // string::npos is returned if string is not found
				{
					input>>dummy;
					cells=(long double *)malloc(sizeof(long double)*3*line_counter);
					for(i=0;i<(number_of_elements-line_counter);i++)
						{
							input>>dummy>>a;
							if(a==15)
							{
								input>>dummy>>dummy>>dummy>>dummy;
							}
							else if(a==1)
							{
								input>>dummy>>dummy>>dummy>>dummy>>dummy;
							}
							else
							{
								cout<<"Neither 15 nor 1"<<endl;
							}
						}
						for(i=0;i<3*line_counter;i=i+3)
						{
							input>>dummy>>dummy>>dummy>>dummy>>dummy>>cells[i]>>cells[i+1]>>cells[i+2];
						}
				}
			}
			input.close();
			
			output.open("cells.txt");
			output<<setprecision(0)<<fixed;
			for(i=0;i<3*line_counter;i=i+3)
			{
				output<<cells[i]<<" "<<cells[i+1]<<" "<<cells[i+2]<<endl;
			}
			output.close();	
		}
		else
		{
			cout<<"File not found!"<<endl;
		}
*/
	
	

	input.open("nose1.txt");
		if(input.is_open())
		{
			while(getline(input,line))
			{
			 	pos = line.find("$Elements");
			  	if(pos!=string::npos) // string::npos is returned if string is not found
        			{
        				input>>dummy;
        				for(i=0;i<((number_of_elements)-(line_counter));i++)
        				{
        					input>>dummy>>a; 
        					if(a==15)
								{
									input>>dummy>>dummy>>dummy>>dummy;
								}
							else
								{
									input>>dummy>>dummy>>dummy>>dummy>>dummy;
								}
						}
						area=(long double *)malloc(sizeof(long double)*line_counter);
						centroid=(long double *)malloc(sizeof(long double)*3*(line_counter));
						normal=(long double *)malloc(sizeof(long double)*3*(line_counter));
						for(i=0;i<(line_counter);i++)
						{
							input>>dummy>>dummy>>dummy>>dummy>>dummy>>a>>b>>c;
							//stores coordinates of respective triangles
							x1_chord=q[(a-1)*3];
							y1_chord=q[((a-1)*3)+1];
							z1_chord=q[((a-1)*3)+2];
							
							x2_chord=q[(b-1)*3];
							y2_chord=q[((b-1)*3)+1];
							z2_chord=q[((b-1)*3)+2];
							
							x3_chord=q[(c-1)*3];
							y3_chord=q[((c-1)*3)+1];
							z3_chord=q[((c-1)*3)+2];
							
							//stores centroid of respective triangles
							j=3*i;
							centroid[j]=(x1_chord+x2_chord+x3_chord)/3;
							centroid[j+1]=(y1_chord+y2_chord+y3_chord)/3;
							centroid[j+2]=(z1_chord+z2_chord+z3_chord)/3;
							
							//calculate side vectors of respective triangles
							k=3*i;
							BA[0]=(x1_chord - x2_chord);
							BA[1]=(y1_chord - y2_chord);
							BA[2]=(z1_chord - z2_chord);
							BC[0]=(x3_chord - x2_chord);
							BC[1]=(y3_chord - y2_chord);
							BC[2]=(z3_chord - z2_chord);
							
							//cross product of sides of respective triangles
							cross_prod[0]=((BA[1]*BC[2]) - (BA[2]*BC[1]));
							cross_prod[1]=((BA[2]*BC[0]) - (BA[0]*BC[2]));
							cross_prod[2]=((BA[0]*BC[1]) - (BA[1]*BC[0]));
							
							//stores normal(unit  vector) of respective triangles
							temp=sqrt(pow(cross_prod[0],2) + pow(cross_prod[1],2) + pow(cross_prod[2],2));
							normal[k]=cross_prod[0]/temp;
							normal[k+1]=cross_prod[1]/temp;
							normal[k+2]=cross_prod[2]/temp;
							
							//calculate and stores area of respective triangles
							area[i]=((0.5)*(temp));
							
							//calculate centroid to triangle point vector of respective triangles
							VC[0]=((x_node/number_of_nodes) - x2_chord);		//Considering x_node is origin
							VC[1]=((y_node/number_of_nodes) - y2_chord);		//Considering y_node is origin	//If not then change it!
							VC[2]=((z_node/number_of_nodes) - z2_chord);		//Considering z_node is origin
							if((VC[0]*normal[k] + VC[1]*normal[k+1] + VC[2]*normal[k+2]) < 0)
							{	//make normals uni-directional
								normal[k]=-normal[k];
								normal[k+1]=-normal[k+1];
								normal[k+2]=-normal[k+2];
							}
							else
							{
								continue;
							}
						}
        			}
			}
			input.close();	
			
			output.open("centroid.txt");	//stores centroids
			output<<setprecision(12)<<fixed;
			for(i=0;i<(3*(line_counter));i=i+3)
			{
				output<<centroid[i]<<" "<<centroid[i+1]<<" "<<centroid[i+2]<<endl;
			}
			output.close();
			
			output.open("area.txt");	//stores areas
			output<<setprecision(12)<<fixed;
			for(i=0;i<line_counter;i++)
			{
				output<<area[i]<<endl;
			}
			output.close();
			
			output.open("normal.txt");	//stores normals
			output<<setprecision(12)<<fixed;
			for(i=0;i<(3*line_counter);i=i+3)
			{
				output<<normal[i]<<" "<<normal[i+1]<<" "<<normal[i+2]<<endl;
			}
			output.close();
			
		}
		else
		{
			cout<<"File not found!"<<endl;
		}

	
	
	
	#define pi 4*atan(1)
	temp=pi;
	cout<<"Enter the A.O.A."<<endl;
	cin>>AOA;
	AOA_rad=AOA*(temp/180);				//stores AOA and convert it into radian
	
	input.open("input_parameters.txt");
	if(input.is_open())
	{
		input>>gama>>p_infinity>>M>>R>>T>>cross_area;	//take values from input_parameters.txt file
	}
	
	else
	{
		cout<<"File not Found!"<<endl;
	}
	input.close();
	
	V_total=M*sqrt(gama*R*T);
	x_coeff=V_total*cos(AOA_rad);
	y_coeff=V_total*sin(AOA_rad);
	z_coeff=0;
	x_coeff=x_coeff/V_total;
	y_coeff=y_coeff/V_total;
	z_coeff=z_coeff/V_total;
	theta=(long double *)malloc(sizeof(long double)*line_counter);
	for(i=0;i<(3*line_counter);i=i+3)
	{	//calculate theta for respective triangles
		dot=((x_coeff*normal[i]) + (y_coeff*normal[i+1]) + (z_coeff*normal[i+2]));
		mod=sqrt(pow(x_coeff,2) + pow(y_coeff,2) + pow(z_coeff,2));
		j=i/3;
		theta[j]=(acos(dot/mod)*(180/temp));
	}
	
	output.open("theta.txt");
	output<<setprecision(12)<<fixed;		//stores theta of respective triangles
	for(i=0;i<line_counter;i++)
	{
		output<<theta[i]<<endl;
	}
	output.close();
	
}
