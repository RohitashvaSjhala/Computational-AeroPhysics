							//Calculation of drag, lift & side_force and their coefficients
void main_operations()
{
	sum=0;
	temp=pi;
	cp=(long double *)malloc(sizeof(long double)*line_counter);
	p=(long double *)malloc(sizeof(long double)*line_counter);
	fi=(long double *)malloc(sizeof(long double)*3*(line_counter));
	input.open("theta.txt");
	if(input.is_open())
	{
		input1.open("normal.txt");
		if(input1.is_open())
		{
			input2.open("area.txt");
			if(input2.is_open())
			{	//switch case for CPmax
				cout<<"Press 1 for CPmax or otherwise 0"<<endl;
				cin>>switch_const;
				for(i=0;i<line_counter;i++)
				{
					input>>theta1;
					input1>>nx>>ny>>nz;
					input2>>ar_ea;
					if(theta1>90)
					{
						cp[i]=0;
						
						p[i]=(((0.5)*(gama)*(p_infinity)*(pow(M,2)))*(cp[i]) + (p_infinity));
						
						j=3*i;
						fi[j]=(p[i]*ar_ea*nx);
						fi[j+1]=(p[i]*ar_ea*ny);
						fi[j+2]=(p[i]*ar_ea*nz);
						
						drag=drag+fi[j];
						lift=lift+fi[j+1];
						side_force=side_force+fi[j+2];	
					}
					else
					{
						phi=90-theta1;
						rad=((phi)*(temp/180));

						switch(switch_const)
						{
							case 0: 
							cp[i]=2*pow(sin(rad),2);
							break;
								
							case 1: 
							cp[i]=CPmax*pow(sin(rad),2);
							break;
						}
						
						
						p[i]=(((0.5)*(gama)*(p_infinity)*(pow(M,2)))*(cp[i]) + (p_infinity));
						
						j=3*i;
						fi[j]=(p[i]*ar_ea*nx);
						fi[j+1]=(p[i]*ar_ea*ny);
						fi[j+2]=(p[i]*ar_ea*nz);
						
						drag=drag+fi[j];
						lift=lift+fi[j+1];
						side_force=side_force+fi[j+2];
						
					}
					cout<<setprecision(12)<<fixed;
				//	cout<<fi[j]<<" "<<fi[j+1]<<" "<<fi[j+2]<<endl;
				}
			}
			else
			{
				cout<<"File not Found!"<<endl;
			}
		}
		else
		{
			cout<<"File not Found!"<<endl;
		}
	}
	else
	{
		cout<<"File not Found!"<<endl;
	}
	cout<<drag<<" "<<lift<<" "<<side_force<<endl;
	cd=fabs(drag/(0.5*pow(M,2)*gama*p_infinity*cross_area));
	cl=fabs(lift/(0.5*pow(M,2)*gama*p_infinity*cross_area));
	cs=fabs(side_force/(0.5*pow(M,2)*gama*p_infinity*cross_area));
	cout<<cd<<endl;
	cout<<cl<<endl;
	cout<<cs<<endl;
	input.close();
	input1.close();
	input2.close();
}
