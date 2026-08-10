clock_t tiempo_inicio = clock();
double limite_tiempo = 1.85;
bool encontrado = false;
while((double)(clock() - tiempo_inicio) / CLOCKS_PER_SEC < limite_tiempo){
    shuffle(all(vector_datos), rng);
    if(evaluar_estado(vector_datos)){
        encontrado = true;
        break;
    }
}
if(!encontrado)
//aqui lanzar un assert(false); para poder saber 
//que el random fallo