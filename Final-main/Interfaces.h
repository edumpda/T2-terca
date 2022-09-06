#ifndef INTERFACES_H
#define INTERFACES_H
#include <string>
#include "Dominios.h"
#include "Entidades.h"

class IServicoAutenticacao;
class IServicoParticipante;
class IServicoPeca;
class IServicoSessao;


class IApresentacaoAutenticacao {
    //180030353
    public:
        virtual bool autenticar(Email*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){};
};



class IApresentacaoParticipante {
    public:
        virtual bool cadastrar() = 0;
        virtual void executar(Email*) = 0;
        virtual void setCntrServicoParticipante(IServicoParticipante*) = 0;
        virtual ~IApresentacaoParticipante(){};
};



class IApresentacaoPSS {
    public:
        virtual void executar(Email*) = 0;
        virtual void executar() = 0;
        virtual void setCntrServicoPeca(IServicoPeca*) = 0;
        virtual void setCntrServicoSessao(IServicoSessao*) = 0;
        virtual ~IApresentacaoPSS(){};

};



class IServicoAutenticacao {
    //190046546
    public:
        virtual bool autenticar(Email*, Senha*) = 0;
};



class IServicoParticipante {
    //200023314
    public:
        virtual bool descadastrar(Email*) = 0;
        virtual bool alterar(Usuario*) = 0;
        virtual bool cadastrar(Usuario*) = 0;
        virtual bool cadastrarEmPeca(Email*, string) = 0;
};


class IServicoPeca{
    //190046546
    public:
        virtual bool incluir(Hospedagem*) = 0;
        virtual bool excluir(Codigo*) = 0;
        virtual bool editar(Hospedagem*) = 0;
        virtual string visualizar(Codigo*) = 0;
        virtual string listar() = 0;

};


class IServicoSessao{
    //190046546
    public:
        virtual bool incluir(Avaliacao*) = 0;
        virtual bool excluir(Codigo*) = 0;
        virtual bool editar(Avaliacao*) = 0;
        virtual string visualizar(Codigo*) = 0;
        virtual string listar() = 0;

};

#endif // INTERFACES_H
