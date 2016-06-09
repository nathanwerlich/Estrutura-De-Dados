/* Copyright 2016 - Nathan Sargon Werlich */
#ifndef NO_BINARIO_HPP
#define NO_BINARIO_HPP

#include <cstdlib>
#include <vector>

template <typename T>
class NoBinario {
 protected:
    T* dado;
    NoBinario<T>* esquerda;
    NoBinario<T>* direita;
    std::vector<NoBinario<T>* > elementos;  //!< Elementos acessados durante
                                            // o percurso realizado

 public:
    NoBinario<T>(const T& dado) {
        this->dado = new T(dado);
        direita = NULL;
        esquerda = NULL;
        elementos.clear();
    }
    virtual ~NoBinario() {
    }
    T* getDado() {
        return dado;
    }
    std::vector< NoBinario<T>* > getElementos() {
        return elementos;
    }
    NoBinario<T>* getEsquerda() {
        return esquerda;
    }
    NoBinario<T>* getDireita() {
        return direita;
    }
    T* busca(const T& dado, NoBinario<T>* arv) {
        while (arv != NULL) {
            if (*arv->getDado() != dado) {
                if (*arv->getDado() < dado) {
                    arv = arv->getDireita();
                } else {
                    arv = arv->getEsquerda();
                }
            } else {
                return arv->getDado();
            }
        }
    throw("!!!!!!!");
    }
    NoBinario<T>* inserir(const T& dado, NoBinario<T>* arv) {
        NoBinario<T>* novo;
        if (dado < *arv->getDado()) {
            if (arv->getEsquerda() == NULL) {
                novo = new NoBinario<T>(dado);
                *novo->getDado() = dado;
                novo->esquerda = NULL;
                novo->direita = NULL;
                arv->esquerda = novo;
            } else {
                arv->inserir(dado, arv->getEsquerda());
            }
        } else {
            if (arv->getDireita() == NULL) {
                novo = new NoBinario<T>(dado);
                *novo->getDado() = dado;
                novo->esquerda = NULL;
                novo->direita = NULL;
                arv->direita = novo;
            } else {
                arv->inserir(dado, arv->getDireita());
            }
        }
        return NULL;
    }
    NoBinario<T>* remover(NoBinario<T>* arv, const T& dado) {
        NoBinario<T> *tmp, *filho;
        if (arv == NULL) {
            return arv;
        } else {
            if (dado < *arv->getDado()) {
                arv->esquerda = remover(arv->getEsquerda(), dado);
                return arv;
            } else {
                if (dado > *arv->getDado()) {
                arv->direita = remover(arv->getDireita(), dado);
                return arv;
                } else {
                    if (arv->getDireita() != NULL &&
                    arv->getEsquerda() != NULL) {
                        tmp = minimo(arv->getDireita());
                        arv->dado = tmp->getDado();
                        arv->direita = remover(arv->getDireita(),
                        *arv->getDado());
                        return arv;
                    } else {
                        tmp = arv;
                        if (arv->getDireita() != NULL) {
                            filho = arv->getDireita();
                            return filho;
                        } else {
                            if (arv->getEsquerda() != NULL) {
                                filho = arv->getEsquerda();
                                return filho;
                            } else {
                            delete arv;
                            return NULL;
                            }
                        }
                    }
                }
            }
        }
    }
    NoBinario<T>* minimo(NoBinario<T>* nodo) {
        while (nodo->getEsquerda() != NULL) {
            nodo = nodo->getEsquerda();
        }
        return nodo;
    }
    void preOrdem(NoBinario<T>* nodo) {
        if (nodo != NULL) {
            elementos.push_back(nodo);
            preOrdem(nodo->getEsquerda());
            preOrdem(nodo->getDireita());
        }
    }
    void emOrdem(NoBinario<T>* nodo) {
        if (nodo != NULL) {
            emOrdem(nodo->getEsquerda());
            elementos.push_back(nodo);
            emOrdem(nodo->getDireita());
        }
    }
    /*
     * @brief Metodo posOrdem
     * @details Caso exista lugar na lista, incrementa a variavel 'fim' e adiciona o parametro
     * 'dado' no vetor 'dados[]' na posição 'fim'
     */
    void posOrdem(NoBinario<T>* nodo) {
        if (nodo != NULL) {
            posOrdem(nodo->getEsquerda());
            posOrdem(nodo->getDireita());
            elementos.push_back(nodo);
        }
    }
};

#endif /* NO_BINARIO_HPP */

