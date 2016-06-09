/* Copyright 2016 - Nathan Sargon Werlich */
#include "ListaEnc.hpp" /*!< inclui o arquivo ListaEnc.hpp */
#include "Elemento.hpp" /*!< inclui o arquivo Elemento.hpp */
template<typename T> /*!< template generico do tipo T*/
/* Classe para a implementação de uma Pilha Encadeada ultilizando herença da classe 
 * ListaEnc onde a mesma é classe 'pai' e PilhaEnc é classe 'filho'
 *   \author Nathan Sargon Werlich.
 *   \since 25/04/16
 *   \version 1.0
 */
class PilhaEnc:ListaEnc<T>{
 public:
    //! Construtor da Classe PilhaEnc
    /*!
     * Inicializado como vazio
     */
    PilhaEnc() {
    }
    //! Destrutor
    /*!
     * Destrutor da classe PilhaEnc. 
     * É chamado o metodo 'LimparPilha()' para eliminar a Pilha por completo
     */
    ~PilhaEnc() {
        limparPilha();
    }
    /*
     * @brief Metodo 'empilha'
     * @details Metodo para adicionar um elemento na Pilha.
     * É chamado o metodo 'adicionaNoInicio()' da classe Pai 'ListaEnc' no metodo 'empilha'
     * @param O parametro 'dado' é o elemento a ser adicionado na Pilha
     */
    void empilha(const T& dado) {
        this->adicionaNoInicio(dado);
    }
	/*
     * @brief Metodo 'desempilha'
     * @details Metodo para retirar um elemento da Pilha.
     * É chamado o metodo 'retiraDoInicio()' da classe Pai 'ListaEnc' no metodo 'desempilha'
     * @return É retornado o metodo 'retiraDoInicio' que é herdado da classe pai 'ListaEnc'
     */
    T desempilha() {
        if (PilhaVazia()) {
            throw "erropilhavazia";
        }
        return this->retiraDoInicio();
    }
    /*
     * @brief Metodo 'top'
     * @details Metodo saber o primeiro elemento da Pilha
     * É chamado o objeto 'cabeca' e feito um 'getInfo' utilizando metodos da classe pai 'ListaEnc'
     * @return É retornado a informação obtida atraves do 'getInfo' de 'cabeca'
     */
	T topo() {
	    if (PilhaVazia()) {
	        throw "ERROLISTAVAZIA";
	    }
	    return this->cabeca->getInfo();
	}
	/*
     * @brief Metodo 'limparPilha'
     * @details Metodo para limpar a Pilha evitando 'lixo' na memoria
     * É chamado o metodo 'destroiLista()' da classe Pai 'ListaEnc' no metodo 'limparPilha'
     * @return É retornado o metodo 'destroiLista()' que é herdado da classe pai 'ListaEnc'
     */
	void limparPilha() {
	    this->destroiLista();
	}
    /*
     * @brief Metodo 'pilhaVazia'
     * @details Metodo para verificar se a Pilha está vazia
     * É chamado o metodo 'listaVazia()' da classe Pai 'ListaEnc' no metodo 'PilhaVazia'
     * @return É retornado o metodo 'listaVazia' que é herdado da classe pai 'ListaEnc'
     */
	bool PilhaVazia() {
	    return this->listaVazia();
	}
};
