#include <stdio.h>
#include <stdlib.h>

int i=0, j=0, p=1, o=1, S=2, M=3;
void arreglo(int Sucursales[S][M], int p);
void pedido_mayor(int pedidos[o][S], int o);
void Medicamento_1();
void Medicamento_2();
void Medicamento_3();
void Medicamento_Buscado();

int main(int argc, char *argv[]) {
	
	int pedidos[o][S], h=0;
	int totals[3][3]={{0,0,0},{0,0,0},{0,0,0}}, cantidad[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	int Sucursal1[2][3]={{1,2,3},{0,0,0}}, Sucursal2[2][3]={{1,2,3},{0,0,0}};
	int Sucursal3[2][3]={{1,2,3},{0,0,0}}, Sucursales[2][3];
	int pedido=0, valor=0, total=0, total1=0, total2=0, total3=0;
	int svc1=0, svc2=0, svc3=0, Medicamento=0;
	
	printf("\n	Numero de pedido: ");
	scanf("%d", &pedido);
	while(pedido>0){
		pedidos[h][0]=pedido;
		pedidos[h][1]=0;
		printf("\nSucursal: ");
		printf("\n	1 - norte ");
		printf("\n	2 - centro ");
		printf("\n	3 - sur ");
		printf("\n	Sucursal: ");
		scanf("%d", &p);
		if(p==1){
			Medicamento_Buscado();
			scanf("%d", &Medicamento);
			switch(Medicamento){
				case 1:
					Medicamento_1();
					scanf("%d", &cantidad[0][0]);
					valor=(1000-(1000*0.05))*cantidad[0][0];
					totals[0][0] = totals[0][0] + valor;
					Sucursal1[1][0]=totals[0][0];
					break;
				case 2:
					Medicamento_2();
					scanf("%d", &cantidad[0][1]);
					valor=(1500-(1500*0.05))*cantidad[0][1];
					totals[0][1] = totals[0][1] + valor;
					Sucursal1[1][1]=totals[0][1];
					break;
				case 3:
					Medicamento_3();
					scanf("%d", &cantidad[0][2]);
					valor=(2000-(2000*0.05))*cantidad[0][2];
					totals[0][2] = totals[0][2] + valor;
					Sucursal1[1][2]=totals[0][2];
					break;
				default:
					printf("\n	Opcion no disponible");
					break;
			}
		}
		else if(p==2){
			Medicamento_Buscado();
			scanf("%d", &Medicamento);
			switch(Medicamento){
				case 1:
					Medicamento_1();
					scanf("%d", &cantidad[1][0]);
					valor=1000 * cantidad[1][0];
					totals[1][0] = totals[1][0] + valor;
					Sucursal2[1][0]=totals[1][0];
					break;
				case 2:
					Medicamento_2();
					scanf("%d", &cantidad[1][1]);
					valor=1500 * cantidad[1][1];
					totals[1][1] = totals[1][1] + valor;
					Sucursal2[1][1]=totals[1][1];
					break;
				case 3:
					Medicamento_3();
					scanf("%d", &cantidad[1][2]);
					valor=2000 * cantidad[1][2];
					totals[1][2] = totals[1][2] + valor;
					Sucursal2[1][2]=totals[1][2];
					break;
				default:
					printf("\n	Opcion no disponible\n");
					break;
			}
		}
		else if(p==3){
			Medicamento_Buscado();
			scanf("%d", &Medicamento);
			switch(Medicamento){
				case 1:
					Medicamento_1();
					scanf("%d", &cantidad[2][0]);
					valor=1000*cantidad[2][0];
					totals[2][0] = totals[2][0] + valor;
					Sucursal3[1][0]=totals[2][0];
					break;
				case 2:
					Medicamento_2();
					scanf("%d", &cantidad[2][1]);
					valor=1500*cantidad[2][1];
					totals[2][1] = totals[2][1] + valor;
					Sucursal3[1][1]=totals[2][1];
					break;
				case 3:
					Medicamento_3();		
					scanf("%d", &cantidad[2][2]);
					valor=2000*cantidad[2][2];
					totals[2][2] = totals[2][2] + valor;
					Sucursal3[1][2]=totals[2][2];
					break;
				default:
					printf("\n	Opcion no disponible\n");
					break;
			}
		}
		else{
			printf("\n	Opcion no disponible\n");
		}
		pedidos[h][1]=valor;
		printf("\n	Numero de pedido: ");
		scanf("%d", &pedido);
		if(pedido!=0) {
			o++;
			h++;
		}
	}
	for(p=1; p<=3; p++){
		if(p==1){
			for(i=0; i<2; i++){
				for(j=0; j<3; j++){
				Sucursales[i][j]=Sucursal1[i][j];
				}
			}
			arreglo(Sucursales, p);
		}
		if(p==2){
			for(i=0; i<2; i++){
				for(j=0; j<3; j++){
				Sucursales[i][j]=Sucursal2[i][j];
				}
			}
			arreglo(Sucursales, p);
		}
		if(p==3){
			for(i=0; i<2; i++){
				for(j=0; j<3; j++){
				Sucursales[i][j]=Sucursal3[i][j];
				}
			}
			arreglo(Sucursales, p);
		}
	}
	for(p=1; p<=3; p++){
		i=p-1;
		printf("\n\nSucursal %d:",p);
		if(cantidad[i][0]<cantidad[i][1] && cantidad[i][0]<cantidad[i][2]){
			printf("\nMedicamento 1 vendio menos unidades");
		}
		else if(cantidad[i][1]<cantidad[i][0] && cantidad[i][1]<cantidad[i][2]){
			printf("\nMedicamento 2 vendio menos unidades");
		}
		else if(cantidad[i][2]<cantidad[i][1] && cantidad[i][2]<cantidad[i][0]){
			printf("\nMedicamento 3 vendio menos unidades");
		}
		else if(cantidad[i][0]==cantidad[i][1] && cantidad[i][0]<cantidad[i][2]){
			printf("\nMedicamento 1 y 2 vendieron menos unidades");
		}
		else if(cantidad[i][0]==cantidad[i][2] && cantidad[i][0]<cantidad[i][1]){
			printf("\nMedicamento 1 y 3 vendieron menos unidades");
		}
		else if(cantidad[i][2]<cantidad[i][0] && cantidad[i][2]==cantidad[i][1]){
			printf("\nMedicamento 2 y 3 vendieron menos unidades");
		}
		else {
			printf("\nTodos los Medicamentos vendieron las mismas unidades");
		}
	}
	for(i=0;i<3;i++){
		total1=total1+totals[0][i];
		total2=total2+totals[1][i];
		total3=total3+totals[2][i];
	}
	total=total1+total2+total3;
	printf("\n\nMonto total de cada sucursal:\n");
	printf(" %dAr$ norte\n", total1);
	printf(" %dAr$ centro\n", total2);
	printf(" %dAr$ sur\n", total3);
	svc1=(total1*100)/total;
	svc2=(total2*100)/total;
	svc3=(total3*100)/total;
	printf("\nPorcentaje que representa lo recaudado por cada sucursal es:\n");
	printf(" %d%\% Sucursal 1\n",svc1);
	printf(" %d%\% Sucursal 2\n",svc2);
	printf(" %d%\% Sucursal 3\n",svc3);

	if(total1>total2 && total1>total3){
		printf("\nLa sucursal con mayor cantidad de pedidos es: norte\n");
	}
	else if(total1==total2 && total1>total3){
		printf("\nLa sucursal con mayor cantidad de pedidos es: norte y centro\n");
	}
	else if(total2>total1 && total2>total3){
		printf("\nLa sucursal con mayor cantidad de pedidos es: centro\n");
	}
	else if(total1==total3 && total1>total2){
		printf("\nLa sucursal con mayor cantidad de pedidos es: norte y sur\n");
	}
	else if(total3>total1 && total3>total2){
		printf("\nLa sucursal con mayor cantidad de pedidos es: sur\n");
	}
	else if(total2==total3 && total2>total1){
		printf("\nLa sucursal con mayor cantidad de pedidos es: centro y sur\n");
	}
	else{
		printf("\nTodas las sucursales tienen la misma cantidad de pedidos\n");
	}
pedido_mayor(pedidos, o);
	return 0;
}
void arreglo(int Sucursales[S][M], int p){
	int aux=0, aux2=0, aux3=0, aux4=0;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(Sucursales[1][i]<Sucursales[1][j]){
				aux=Sucursales[1][i];
                aux3=Sucursales[0][i];
                aux2=Sucursales[1][j];
                aux4=Sucursales[0][j];
	            Sucursales[1][i]=aux2;
    	        Sucursales[0][i]=aux4;
        	    Sucursales[1][j]=aux;
            	Sucursales[0][j]=aux3;
		    }
        }
    }
		printf("\n\nRecaudo en orden de Menor a Mayor:");
		printf("\nSucursal %d:",p);
		printf("\n %dAr$ Medicamento %d", Sucursales[1][0], Sucursales[0][0]);
		printf("\n %dAr$ Medicamento %d", Sucursales[1][1], Sucursales[0][1]);
		printf("\n %dAr$ Medicamento %d", Sucursales[1][2], Sucursales[0][2]);
}
void pedido_mayor(int pedidos[o][S], int o){
	int aux=0, aux2=0, aux3=0, aux4=0;
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(pedidos[i][1]>pedidos[j][1]){
				aux=pedidos[i][1];
                aux3=pedidos[i][0];
                aux2=pedidos[j][1];
                aux4=pedidos[j][0];
	            pedidos[i][1]=aux2;
    	        pedidos[i][0]=aux4;
        	    pedidos[j][1]=aux;
            	pedidos[j][0]=aux3;
		    }
        }
    }
		printf("\nPedido %d Monto total %dAr$\n", pedidos[0][0], pedidos[0][1]);
}
void Medicamento_1(){
	printf("\n	Valor: 1000Ar$");
	printf("\n	Medicamento para el Dolor de Cabeza\n");
	printf("\nCantidad a solicitar: ");
}
void Medicamento_2(){
	printf("\n	Valor: 1500Ar$");
	printf("\n	Medicamento para la Fiebre\n");
	printf("\n	Cantidad a solicitar: ");
}
void Medicamento_3(){
	printf("\n	Valor: 2000Ar$");
	printf("\n	Medicamento para el Asma\n");
	printf("\n	Cantidad a solicitar: ");
}
void Medicamento_Buscado(){
	printf("\nQue Medicamento Busca: ");
	printf("\n	1 - Medicamento 1");
	printf("\n	2 - Medicamento 2");
	printf("\n	3 - Medicamento 3");
	printf("\n	Medicamento: ");
}
