cadena_t insertar_antes(info_t i, localizador_t loc, cadena_t cad);

cadena_t cortar_segmento(localizador_t desde, localizador_t hasta, cadena_t cad);

cadena_t remover_de_cadena(localizador_t &loc, cadena_t cad);

localizador_t kesimo(nat k, cadena_t cad);

info_t info_cadena(localizador_t loc, cadena_t cad);

cadena_t intercambiar(localizador_t loc1, localizador_t loc2, cadena_t cad);

void imprimir_cadena(cadena_t cad);

cadena_t insertar_antes(info_t i, localizador_t loc, cadena_t cad);
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
cadena_t cortar_segmento(localizador_t desde, localizador_t hasta, cadena_t cad)
{
  assert(precede_en_cadena(desde, hasta, cad) || es_vacia_cadena(cad));
  if (es_vacia_cadena(cad))
    return cad;
  else
  {
    nodo *a_borrar;
    while (desde != hasta)
    {
      a_borrar = desde;
      desde = desde->siguiente;
      liberar_info(a_borrar->dato);
      delete (a_borrar);
    }
    a_borrar = hasta;
    hasta = hasta->siguiente;
    liberar_info(a_borrar->dato);
    delete (a_borrar);
    return cad;
  }
}

void imprimir_cadena(cadena_t cad)
{
  localizador_t res;
  if (es_cadena_vacia(cad))
    printf("/n");
  else
  {
    res = cad->inicio while (res != cad->final)
    {
      printf("%d", info_a_texto(res->info));
      res = res->siguiente;
    }
    printf("%d\n", info_a_texto(cad->final));
  }
}

localizador_t kesimo(nat k, cadena_t cad);
{
  int cont = 1;
  localizador_t cursor = inicio_cadena(cad);
  while ((cont != k) && (cursor->siguiente != NULL))
  {
    cursor = siguiente(cursor, cad);
    ++cont;
  }
  if (cont = k)
    return cursor;
  else
    return NULL;
}