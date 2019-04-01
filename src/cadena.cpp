#include "../include/cadena.h"
#include "../include/info.h"

#include <stddef.h>
#include <stdio.h>
#include <assert.h>

struct nodo
{
    info_t dato;
    nodo *anterior;
    nodo *siguiente;
};

struct rep_cadena
{
    nodo *inicio;
    nodo *final;
};

cadena_t crear_cadena()
{
    cadena_t res = new rep_cadena;
    res->inicio = res->final = NULL;
    return res;
}

cadena_t insertar_al_final(info_t i, cadena_t cad)
{
    nodo *nuevo = new nodo;
    nuevo->dato = i;
    nuevo->siguiente = NULL;
    nuevo->anterior = cad->final;
    if (cad->final == NULL)
    {
        assert(cad->inicio == NULL);
        cad->inicio = nuevo;
    }
    else
    {
        assert(cad->inicio != NULL);
        cad->final->siguiente = nuevo;
    }
    cad->final = nuevo;
    return cad;
}

cadena_t insertar_segmento_despues(cadena_t &sgm, localizador_t loc, cadena_t cad)
{
    assert(es_vacia_cadena(cad) || localizador_en_cadena(loc, cad));
    if (es_vacia_cadena(cad))
    {
        cad->inicio = sgm->inicio;
        cad->finalL = sgm->final;
    }
    else
    {
        if (!es_vacia_cadena(sgm))
        {
            sgm->inicio->anterior = loc;
            sgm->final->siguiente = loc->siguiente;
            if (es_final_cadena(loc, cad))
                cad->final = sgm->final;
            else
                loc->siguiente->anterior = sgm->final;

            loc->siguiente = sgm->inicio;
        }
    }
    sgm->inicio = sgm->final = NULL;
    return cad;
}

cadena_t copiar_segmento(localizador_t desde, localizador_t hasta, cadena_t cad)
{
    assert(es_vacia_cadena(cad) || precede_en_cadena(desde, hasta, cad));
    cadena_t res = crear_cadena();
    if (!es_vacia_cadena(cad))
    {
        localizador_t loc = desde;
        while (loc != siguiente(hasta, cad))
        {
            info_t info = copia_info((loc->dato));
            insertar_al_final(info, res);
            loc = siguiente(loc, cad);
        }
    }
    return res;
}

cadena_t liberar_cadena(cadena_t cad)
{
    nodo *a_borrar;
    while (cad->inicio != NULL)
    {
        a_borrar = cad->inicio;
        cad->inicio = cad->inicio->siguiente;
        liberar_info(a_borrar->dato);
        delete (a_borrar);
    }
    delete cad;
    return cad;
}

bool es_localizador(localizador_t loc) { return loc != NULL; }

bool es_vacia_cadena(cadena_t cad)
{
    return (cad->inicio == NULL) && (cad->final == NULL);
}

localizador_t inicio_cadena(cadena_t cad)
{
    localizador_t res;
    if (es_vacia_cadena(cad))
    {
        res = NULL;
    }
    else
    {
        res = cad->inicio;
    }
    return res;
}
bool localizador_en_cadena(localizador_t loc, cadena_t cad)
{
    localizador_t cursor = inicio_cadena(cad);
    while (es_localizador(cursor) && (cursor != loc))
        cursor = siguiente(cursor, cad);
    return es_localizador(cursor);
}

localizador_t menor_en_cadena(localizador_t loc, cadena_t cad)
{
    assert(localizador_en_cadena(loc, cad));
    localizador_t res = loc;
    while (es_localizador(siguiente(loc, cad)))
    {
        loc = siguiente(loc, cad);
        if (numero_info(info_cadena(loc, cad)) < numero_info(info_cadena(res, cad)))
            res = loc;
    }
    return res;
}

localizador_t siguiente_clave(int clave, localizador_t loc, cadena_t cad)
{
    assert(es_vacia_cadena(cad) || localizador_en_cadena(loc, cad));
    localizador_t res = loc;
    if (es_vacia_cadena(cad))
        res = NULL;
    else
    {
        while (es_localizador(res) && numero_info(info_cadena(res, cad)) != clave)
            res = siguiente(res, cad);
    }
    return res;
}

cadena_t cambiar_en_cadena(info_t i, localizador_t loc, cadena_t cad)
{
    assert(localizador_en_cadena(loc, cad));
    loc->dato = i;
    return cad;
}

localizador_t siguiente(localizador_t loc, cadena_t cad);
{
    localizador_t res;
    res = NULL if (localizador_en_cadena(loc, cad))
        res = loc->siguiente;
    return res;
}

localizador_t anterior(localizador_t loc, cadena_t cad);
{
    localizador_t res;
    res = NULL if (localizador_en_cadena(loc, cad))
        res = loc->anterior;
    return res;
}

bool es_final_cadena(localizador_t loc, cadena_t cad);
{
    if (es_vacia_cadena(cad))
    {
        return false
    }
    else
    {
        return !es_localizador(siguiente(loc, cad))
    }
}

bool es_inicio_cadena(localizador_t loc, cadena_t cad);
{
    if (es_vacia_cadena(cad))
    {
        return false
    }
    else
    {
        return !es_localizador(anterior(loc, cad))
    }
}

bool precede_en_cadena(localizador_t loc1, localizador_t loc2, cadena_t cad);
{
    localizador_t res = loc1;
    if (res == loc2)
        return true;
    else
    {
        while ((res != loc2) && es_localizador(siguiente(res, cad)))
            res = siguiente(res, cad);
        return res == loc2;
    }
}

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

cadena_t cortar_segmento(localizador_t desde, localizador_t hasta, cadena_t cad);
{
    assert(precede_en_cadena(desde, hasta, cad) || es_vacia_cadena(cad)) if es_vacia_cadena(cad) return cad;
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