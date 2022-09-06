#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <unordered_map>
#include "Dominios.h"
#include "Entidades.h"

using namespace std;





class ContainerParticipante {
    //200023314
    public:
        typedef unordered_map<string, Usuario> cmap;
        static ContainerParticipante* getInstancia();
        bool incluir(Usuario* usuario);
        bool remover(string key);
        Usuario* pesquisar(string key);
        bool atualizar(Usuario* usuario);
        cmap getMap(){return container;};

    private:
        cmap container;
        static ContainerParticipante *instancia;
        ContainerParticipante(){};
};



class ContainerPeca {
    public:
        typedef unordered_map<string, Hospedagem> cmap;
        static ContainerPeca* getInstancia();
        bool incluir(Hospedagem* hospedagem);
        bool remover(string key);
        Hospedagem* pesquisar(string key);
        bool atualizar(Hospedagem* hospedagem);
        int contar(string key);
        cmap getMap(){return container;};

    private:
        cmap container;
        static ContainerPeca *instancia;
        ContainerPeca(){};
};



class ContainerSessao {
    //200023314
    public:
        typedef unordered_map<string, Avaliacao> cmap;
        static ContainerSessao* getInstancia();
        bool incluir(Avaliacao* avaliacao);
        bool remover(string key);
        Avaliacao* pesquisar(string key);
        bool atualizar(Avaliacao* avaliacao);
        cmap getMap(){return container;};

    private:
        cmap container;
        static ContainerSessao *instancia;
        ContainerSessao(){};
};




class Peca2Participante {
    //200023314
    private:
        typedef unordered_multimap<string, string> map;
        map container;
        static Peca2Participante *instancia;

    public:
        static Peca2Participante* getInstancia();
        bool incluir(string peca, string participante);
        void removerPeca(string peca);
        void removerParticipante(string participante);
        int contar(string peca);
};



#endif // CONTAINER_H
