#include "Dominios.h"

#ifndef ENTIDADES_H
#define ENTIDADES_H

/// 
/// Classe para entidade participante
///

class Usuario {
    //180030353
    private:
        Email email;
        Nome nome;
        Idioma idioma;
        Senha senha;
        Aniversario aniversario;
        Descricao descricao;

    public:

///
/// Armazena matrícula.
/// @param valor Objeto de classe Matrícula
///
        void setEmail(const Email &valor);
///
/// Retorna matrícula.
/// @return valor
///
///
        Email getEmail();
///
/// Armazena nome.
/// @param valor Objeto de classe Nome
///
        void setNome(const Nome &valor);
///
/// Retorna Nome.
/// @return valor
///
        Nome getNome();
///
///
/// Armazena telefone.
/// @param valor Objeto de classe Telefone
///
        void setIdioma(const Idioma &valor);
///
/// Retorna telefone.
/// @return valor
///
        Idioma getIdioma();
///
/// Armazena senha.
/// @param valor Objeto de classe Senha
///
        void setSenha(const Senha &valor);
///
/// Retorna senha.
/// @return valor
///
        Senha getSenha();
///
/// Armazena cargo.
/// @param valor Objeto de classe Cargo
///
        void setAniversario(const Aniversario &valor);
///
/// Retorna cargo.
/// @return valor
///
        Aniversario getAniversario();///
/// Armazena descricao.
/// @param valor Objeto de classe descricao
///
        void setDescricao(const Descricao &valor);
///
/// Retorna cargo.
/// @return valor
///
        Descricao getDescricao();
};

inline void Usuario::setEmail(const Email &valor){
    email = valor;
}

inline Email Usuario::getEmail(){
    return email;
}

inline void Usuario::setNome(const Nome &valor){
    nome = valor; 
}

inline Nome Usuario::getNome(){
    return nome;
}

inline void Usuario::setIdioma(const Idioma &valor){
    idioma = valor;
}

inline Idioma Usuario::getIdioma(){
    return idioma;
}

inline void Usuario::setAniversario(const Aniversario &valor){
    aniversario = valor;
}

inline Aniversario Usuario::getAniversario() {
    return aniversario;
}

inline void Usuario::setDescricao(const Descricao &valor) {
    descricao = valor;
}

inline Descricao Usuario::getDescricao() {
    return descricao;
}

inline void Usuario::setSenha(const Senha &valor){
    senha = valor; 
}

inline Senha Usuario::getSenha(){
    return senha;
}


/// 
/// Classe para entidade Peça
///

class Hospedagem {
    //190046546
    private:
        Codigo codigo;
        Cidade cidade;
        Pais pais;
        Nota nota;
        Descricao descricao;

    public:
///
/// Armazena identificador.
/// @param valor Objeto da classe Código.
///
        void setCodigo(const Codigo &valor);
///
/// Retorna identificador.
/// @return valor
///
        Codigo getCodigo();
///
/// Armazena nome.
/// @param valor Objeto da classe Nome.
///
        void setCidade(const Cidade &valor);
///
/// Retorna nome.
/// @return valor
///
        Cidade getCidade();
///
/// Armazena tipo.
/// @param valor Objeto da classe Tipo.
///
        void setPais(const Pais &valor);
///
/// Retorna tipo.
/// @return valor
///
        Pais getPais();
///
/// Armazena classificação.
/// @param valor Objeto da classe Classificação.
///
        void setNota(const Nota &valor);
///
/// Retorna classificação.
/// @return valor
///
        Nota getNota();
        void setDescricao(const Descricao &valor);
///
/// Retorna classificação.
/// @return valor
///
        Descricao getDescricao();
};

inline void Hospedagem::setCodigo(const Codigo &valor) {
    codigo = valor;
}

inline Codigo Hospedagem::getCodigo() {
    return codigo;
}

inline void Hospedagem::setCidade(const Cidade &valor) {
    cidade = valor;
}

inline Cidade Hospedagem::getCidade() {
    return cidade;
}

inline void Hospedagem::setPais(const Pais &valor){
    pais = valor;
}

inline Pais Hospedagem::getPais() {
    return pais;
}

inline void Hospedagem::setNota(const Nota &valor){
    nota = valor;
}

inline Nota Hospedagem::getNota() {
    return nota;
}
inline void Hospedagem::setDescricao(const Descricao &valor) {
    descricao = valor;
}

inline Descricao Hospedagem::getDescricao() {
    return descricao;
}

/// 
/// Classe para entidade Sessão
///

class Avaliacao {
    private:
        Codigo codigo;
        Nota nota;
        Descricao descricao;

    public:
///
/// Armazena identificador.
/// @param valor Objeto da classe Código.
///
        void setCodigo(const Codigo &valor);
///
/// Retorna identificador.
/// @return valor
///
        Codigo getCodigo();
///
/// Armazena data.
/// @param valor Objeto da classe Data.
///
        void setNota(const Nota &valor);
///
/// Retorna data.
/// @return valor
///
        Nota getNota();
///
/// Armazena horário.
/// @param valor Objeto da classe Horário.
///
        void setDescricao(const Descricao &valor);
///
/// Retorna horário.
/// @return valor
///
        Descricao getDescricao();
};

inline void Avaliacao::setCodigo(const Codigo &valor) {
    codigo = valor;
}

inline Codigo Avaliacao::getCodigo() {
    return codigo;
}

inline void Avaliacao::setNota(const Nota &valor) {
    nota = valor;
}

inline Nota Avaliacao::getNota(){
    return nota;
}

inline void Avaliacao::setDescricao(const Descricao &valor){
    descricao = valor;
}

inline Descricao Avaliacao::getDescricao() {
    return descricao;
}

#endif
