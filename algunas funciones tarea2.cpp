localizador_t siguiente(localizador_t loc, cadena_t cad); {
     localizador_t res;
     res = NULL
     if (localizador_en_cadena(loc, cad)) 
        res = loc->siguiente;
     return res; 
}     

localizador_t anterior(localizador_t loc, cadena_t cad); {
     localizador_t res;
     res = NULL
     if (localizador_en_cadena(loc, cad)) 
        res = loc->anterior;
     return res; 
}     

bool es_final_cadena(localizador_t loc, cadena_t cad); {
     if (es_vacia_cadena(cad)) {
        return false }
     else {
        return !es_localizador(siguiente(loc, cad)) }
}

bool es_inicio_cadena(localizador_t loc, cadena_t cad); {
     if (es_vacia_cadena(cad)) {
        return false }
     else {
        return !es_localizador(anterior(loc, cad)) }
}

bool precede_en_cadena(localizador_t loc1, localizador_t loc2, cadena_t cad); {
     localizador_t res = loc1;
     if (res == loc2)
       return true;
     else {
       while ((res != loc2) && es_localizador(siguiente(res, cad)))  
         res = siguiente(res, cad);
     return res == loc2;
          }
}

