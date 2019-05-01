void CPmax_fun()
{
	constant1=(pow((pow(gama+1,2)*pow(M,2))/((4*gama*pow(M,2))-(2*gama-2)),(gama/(gama-1))) * ((1-gama+(2*gama*pow(M,2)))/(gama+1)));
	constant2=(gama/2)*pow(M,2);
	CPmax=(constant1-1)/constant2;
}
