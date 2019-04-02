bool pertenece(int i, cadena_t cad); {
    localizador_t res = cad->inicio
    if (!es_vacia_cadena(cad)) {
        while (res->dato->num != i) {
            res = siguiente(res, cad);
        }    
    }
    if (es_localizador(res)) {
        return true;
    }
    else return false;
}

nat longitud(cadena_t cad); {
    nat cant = 0;
    localizador_t res = cad->inicio;
    while (es_localizador(res)) {
        ++cant;
        res = siguiente(res, cad);
    }
    return cant
}

bool esta_ordenada(cadena_t cad); {
    if(es_vacia_cadena(cad))
       return true;
    else {
        localizador_t res1 = cad->inicio;
        localizador_t res2 = siguiente(res1, cad);
        bool res = true;
        while (es_localizador(res2) && res) {
            res = (res2->dato->num >= res1->dato->num);
            res1 = res2;
            res2 = siguiente(res2, cad);
        }
        return res;
    }

}

cadena_t concatenar(cadena_t c1, cadena_t c2); {
    cadena_t res = crear_cadena();
    cadena_t res1 = copiar_segmento(c1->inicio; c1->final; c1);
    cadena_t res2 = copiar_segmento(c2->inicio; c2->final; c2);
    insertar_segmento_despues(&res1; res->inicio; res);
    insertar_segmento_despues(&res2; res->final; res);
    return res;
}

cadena_t cambiar_todos(int original, int nuevo, cadena_t cad); {
    localizador_t res = cad->inicio;
    if (es_localizador(res)) {
        if (res->dato->num == original)
           res->dato->num = nuevo;
        while (es_localizador(siguiente(res, cad))) {
             res = siguiente(res, cad);
             if (res->dato->num == original)
                res->dato->num = nuevo;
         }   
    }
    return res;
}
