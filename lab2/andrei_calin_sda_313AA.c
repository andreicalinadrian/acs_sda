#include <stdio.h>
#include <stdlib.h>

typedef struct{	unsigned short  mantisa;
				unsigned char   exponent;
			}fp;

fp  a,b,c;

fp fpadd(fp a,fp b)
{
	unsigned char	sa,sb,sc;
	unsigned short	ma,mb;
	unsigned long	mc;
	unsigned char	ea,eb,ec;
	fp			c;

	// Extrage valorile mantiselor si exponentilor din numerele primite ca parametrii
	ma=a.mantisa;
	mb=b.mantisa;
	ea=a.exponent;
	eb=b.exponent;

	// Extrage semnul celor doua numere
	if(ma&0x8000)
	    sa=1;
	  else
	    sa=0;
	if(mb&0x8000)
	    sb=1;
	  else
	    sb=0;

	// Completeaza bitul implicit din mantise
	ma|=0x8000;
	mb|=0x8000;

	// Aduce la acelasi exponent
	if(ea>eb){
		ec=ea;
		mb>>=ea-eb;
		}
	  else{
		ec=eb;
		ma>>=eb-ea;
		}

	// Efectueaza operatia de calcul asupra mantiselor
	if(sa==0 && sb==0){
		mc=ma+mb;
		sc=0;
		}
	if(sa==1 && sb==1){
		mc=ma+mb;
		sc=1;
		}
	if(sa==0 && sb==1)
	    if(ma>=mb){
			mc=ma-mb;
			sc=0;
			}
		  else{
			mc=mb-ma;
			sc=1;
			}
	if(sa==1 && sb==0)
	    if(ma>=mb){
			mc=ma-mb;
			sc=1;
			}
		  else{
			mc=mb-ma;
			sc=1;
			}
//Cazul in care unul din operanzi este 0
	if((ma|0x0)==0x0)
    {
        c.mantisa=mb;
        c.exponent=eb;
        return (c);
    }

//cazul in care dinferenta dintre exponenti este mai mare decat 16
    if((ea-eb)>16)
    {
        c.mantisa=ma;
        c.exponent=ea;
        return (c);
    }
    if((eb-ea)>16)
    {
        c.mantisa=mb;
        c.exponent=eb;
        return (c);
    }

 //cazul in care mantisa calculata este 0
    if(mc==0x0)
    {
        c.mantisa=0x0;
        c.exponent=ec;
        return (c);
    }

 //Verificare in cazul depasiri
    if(ec>=255)
    {
        if(mc>0x0)
            c.mantisa=(double)INFINITY;
        else c.mantisa=(double)-INFINITY;
        return (c);
    }
        //Verificare in cazul depasiri vaorii minime;
    if(ec<=0)
    {
        c.mantisa=0x0;
        c.exponent=0;
        return (c);
    }
	// Testeaza daca rezultatul trebuie normalizat prin deplasare la stinga
	if(mc>=0x10000){
		mc>>=1;
		ec++;
		}

	// Testeaza daca rezultatul trebuie normalizat prin deplasare la dreapta
	while(0==(mc&0x8000)){
	    mc<<=1;
	    ec--;
		}

	// Copiaza semnul
	if(sc==0)
	    mc&=0x7FFF;
	  else
	    mc|=0x8000;

	// Scrie rezultatul
	c.mantisa=(unsigned short)mc;
	c.exponent=ec;

	return(c);
}


int main(int argc, char *argv[])
{
	a.mantisa=0x2C00;
	a.exponent=127+3;

	b.mantisa=0x5000;
	b.exponent=127+0;

	c=fpadd(a,b);

	printf("Mantisa: %04X\tExponent:%d\n",c.mantisa,c.exponent-127);

	system("PAUSE");
	return(0);
}
