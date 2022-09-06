#ifndef CONTROLES_SERVICO_H
#define CONTROLES_SERVICO_H

#include <string>
#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"



class CntrServicoAutenticacao: public IServicoAutenticacao {
    //190046546
    public:
        bool autenticar(Email* email, Senha* senha) override;

};


class CntrServicoParticipante: public IServicoParticipante {
    //200023314
    public:
        bool descadastrar(Email *email) override;
        bool alterar(Usuario *usuario) override;
        bool cadastrar(Usuario *usuario) override;
        bool cadastrarEmPeca(Email *email, string peca) override;
};


class CntrServicoPeca: public IServicoPeca {
    //190046546
    public:
        bool incluir(Hospedagem *hospedagem) override;
        bool excluir(Codigo *codigo) override;
        bool editar(Hospedagem *hospedagem) override;
        string visualizar(Codigo *codigo) override;
        string listar() override;
};


class CntrServicoSessao: public IServicoSessao {
    //190046546
    public:
        bool incluir(Avaliacao *avaliacao) override;
        bool excluir(Codigo *codigo) override;
        bool editar(Avaliacao *avaliacao) override;
        string visualizar(Codigo *codigo) override;
        string listar() override;
};




#endif // CONTROLES_SERVICO_H
