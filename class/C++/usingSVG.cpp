#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ofstream svgfile;

const string headString0 = "<?xml version=\"1.0\" standalone=\"no\"?>";
const string headString1 = "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">";

void SVG_Begin(string width="100%",string height="100%")
{
	svgfile << headString0 << endl;
	svgfile << headString1 << endl;
    
	string head="<svg width=\""+width+"\" height=\""+height+"\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";
	
	svgfile<<head<<endl;
	
}

void SVG_end()
{
	
	svgfile<<"</svg>"<<endl;
	svgfile.close();
}

void SVG_drawCircle(string x,string y,string r,string stroke="#0000FF",string strokewidth="2",string fill="#FF0000")
{
	string circle="<circle cx=\""+x+"\" cy=\""+y+"\" r=\""+r+"\" stroke=\""+stroke+"\" stroke-width=\""+strokewidth+"\" fill=\""+fill+"\"/>";
	svgfile<<circle<<endl;
	
}

void SVG_drawRect(string width,string height,string stroke="#0000FF",string strokewidth="2",string fill="#FF0000")
{
	string rect="<rect width=\""+width+"\" height=\""+height+"\"  stroke=\""+stroke+"\" stroke-width=\""+strokewidth+"\" fill=\""+fill+"\"/>";
	svgfile<<rect<<endl;
	
}

int main()
{

	svgfile.open("d:\\myshape.svg",ios::out);
	SVG_Begin("100%","100%");

	SVG_drawCircle("300","100","100");
	SVG_drawRect("200","200");


	SVG_end();
	
	
	
	system("pause");
    return 0;
}