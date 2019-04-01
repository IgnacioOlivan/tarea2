cadena_t insertar_antes(info_t i, localizador_t loc, cadena_t cad)

    cadena_t cortar_segmento(localizador_t desde, localizador_t hasta,
                             cadena_t cad)

        cadena_t remover_de_cadena(localizador_t &loc, cadena_t cad)

            localizador_t kesimo(nat k, cadena_t cad);

info_t info_cadena(localizador_t loc, cadena_t cad)

    cadena_t intercambiar(localizador_t loc1, localizador_t loc2, cadena_t cad);

void imprimir_cadena(cadena_t cad);

cadena_t insertar_antes(info_t i, localizador_t loc, cadena_t cad)
{
  assert(localizador_en_cadena(loc, cad));
  nodo *nuevo = new nodo;
  nuevo->dato = i;
  nuevo->siguiente = loc;
  nuevo->anterior = loc->anterior;
  return cad;
}

cadena_t remover_de_cadena(localizador_t &loc, cadena_t cad)
{
  nodo *a_borrar;
  a_borrar = cad->loc;
  cad->loc = cad->siguiente;
  liberar_info(a_borrar->dato);
  delete (a_borrar);
}

info_t info_cadena(localizador_t loc, cadena_t cad)
{
  assert(localizador_en_cadena(loc, cad));
  return loc->dato;
}
