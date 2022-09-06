#include <string>
#include <regex>

#ifndef DOMINIOS_H
#define DOMINIOS_H

using namespace std;


///
/// Classe base para todos os domínios.
///
///
///

class Dominio {
    private:
        string valor;
        virtual void validar(string valor) = 0;

    public:

///
/// Destrutor virtual para evitar comportamento indefinido.
///

        virtual ~Dominio(){};

///
/// Armazena valor.
/// @param valor Valor do domínio representado em string.
/// @throw invalid_argument
///

        void setValor(string valor);

///
/// Retorna valor.
/// @return valor
///
///

        string getValor();

};


inline string Dominio::getValor(){
    return valor;
}


///
/// Classe para representar capacidade.
/// Regras de formato:
/// - Capacidade é válida se for igual a 100, 200, 300, 400 ou 500.
///

class Cidade: public Dominio {
    private:
        static const regex FORMATO;
//        static constexpr int ACEITOS[5] = {100, 200, 300, 400, 500};
        void validar(string valor) override;
};


///
/// Classe para representar cargo.
/// Regras de formato:
/// - Cargo é válido se for igual a ator, cenógrafo, figurinista, maquiador, sonoplasta ou iluminador.
///

class Pais: public Dominio {
    //190046546
    private:
        void validar(string valor);
};

///
/// Classe para representar classificação.
/// Regras de formato:
/// - Classificação é válida se for igual a livre, 10, 12, 14, 16 ou 18.
///

class Descricao: public Dominio {
    //190046546
    private:
        void validar(string valor) override;
};

///
/// Classe para representar código.
/// Regras de formato:
/// - Código é válido se for igual a LLDDDD.
/// - L é letra maiúscula.
/// - D é dígito.
///

class Codigo: public Dominio {
    //200023314
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

///
/// Classe para representar data.
/// Regras de formato:
/// - Data é válida se for igual a DD/MM/AAAA.
/// - DD de 01 a 31.
/// - MM de 01 a 12.
/// - AAAA de 2000 a 9999.
/// - Leva em consideração anos bissextos.
///

class Nota: public Dominio {
    //200023314
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


///
/// Classe para representar email.
/// Regras de formato:
/// - Email é válido se for igual a parte-local@domínio.
/// - parte-local é composta por até 64 caracteres.
/// - domínio é composto por até 255 caracteres.
/// - Caractere pode ser letra maiúscula, letra minúscula, dígito, um dos caracteres: ! # $ % & ' * + - / = ? ^ _ ` { | } ~ ou ponto.
/// - Ponto não pode ser o primeiro ou último caractere, e não pode ocorrer em sequência.
///

class Email: public Dominio {

    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

///
/// Classe para representar horário.
/// Regras de formato:
/// - Horário é válido se for igual a HH:MM.
/// - HH de 00 a 23.
/// - MM é 00, 15, 30 ou 45.
///

class Aniversario: public Dominio {
    //200023314
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


class Nome: public Dominio {
    //180030353
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

///
/// Classe para representar Senha.
/// Regras de formato:
/// - Senha é válida se for igual a XXXXXXXX.
/// - X é letra, dígito ou um dos caracteres especiais ! @ # $ % & ?.
/// - Não pode existir caractere repetido.
/// - Existe pelo menos uma letra (maiúscula ou minúscula), um dígito e um caractere especial.
///

class Senha: public Dominio {
    //180030353
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};


class Idioma: public Dominio {
    //180030353
    private:
        static const regex FORMATO;
        void validar(string valor) override;
};

#endif // DOMINIOS_H
