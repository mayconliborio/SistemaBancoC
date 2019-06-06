typedef struct Aluno Aluno;
typedef struct Aproveitamento Aproveitamento;
typedef struct Turma Turma;
typedef struct Disciplina Disciplina;
typedef struct Professor Professor;

struct Aluno{
	char nome[80];
	int ra;
	Aproveitamento *aproveitamento;
	Aluno *aluno;
};

struct Aproveitamento{
	float notas[3];
	float frequencwia;
	Turma *turma;
	Aproveitamento *aproveitamento;
};

struct Turma{
	int codigo;
	int ano;
	char semestre;
	char situacao;
	Professor *professor;
	Disciplina *disciplina;
	Aluno *Alunos;
	Turma *turma;
};

struct Disciplina{
	int codigo;
	int cargahoraria;
	char nome[50];
	Disciplina *disciplina;
};

struct Professor{
	char nome[80];
	int anoEntrada;
	int anoSaida;
	Turma *turmas;
	Professor *professor;
}; 