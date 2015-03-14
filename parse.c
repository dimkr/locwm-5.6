#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140101

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 23 "parse.y"

#include <sys/param.h>
#include <sys/queue.h>

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calmwm.h"

TAILQ_HEAD(files, file)		 files = TAILQ_HEAD_INITIALIZER(files);
static struct file {
	TAILQ_ENTRY(file)	 entry;
	FILE			*stream;
	char			*name;
	int			 lineno;
	int			 errors;
} *file, *topfile;
struct file	*pushfile(const char *);
int		 popfile(void);
int		 yyparse(void);
int		 yylex(void);
int		 yyerror(const char *, ...);
int		 kw_cmp(const void *, const void *);
int		 lookup(char *);
int		 lgetc(int);
int		 lungetc(int);
int		 findeol(void);

static struct conf	*conf;

typedef struct {
	union {
		int64_t			 number;
		char			*string;
	} v;
	int lineno;
} YYSTYPE;

#line 64 "parse.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define FONTNAME 257
#define STICKY 258
#define GAP 259
#define MOUSEBIND 260
#define AUTOGROUP 261
#define BIND 262
#define COMMAND 263
#define IGNORE 264
#define YES 265
#define NO 266
#define BORDERWIDTH 267
#define MOVEAMOUNT 268
#define COLOR 269
#define SNAPDIST 270
#define ACTIVEBORDER 271
#define INACTIVEBORDER 272
#define URGENCYBORDER 273
#define GROUPBORDER 274
#define UNGROUPBORDER 275
#define MENUBG 276
#define MENUFG 277
#define FONTCOLOR 278
#define FONTSELCOLOR 279
#define ERROR 280
#define STRING 281
#define NUMBER 282
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    2,    2,    1,    1,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    4,    5,    5,    5,    5,    5,    5,    5,    5,    5,
};
static const short yylen[] = {                            2,
    0,    2,    3,    3,    3,    2,    1,    1,    1,    2,
    2,    2,    2,    2,    3,    3,    2,    3,    5,    3,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
};
static const short yydefred[] = {                         1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    2,    0,    0,    5,   10,    8,
    9,   11,    0,    0,    0,    0,    0,   17,   12,   13,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   21,
   14,    3,    4,    0,    7,    0,   16,    0,    0,   22,
   23,   24,   25,   26,   27,   28,   29,   30,    0,    6,
   19,
};
static const short yydgoto[] = {                          1,
   22,   46,   16,   17,   40,
};
static const short yysindex[] = {                         0,
  -10,    4, -266, -255, -265, -263, -262, -260, -259, -258,
 -257, -256, -270, -254,    0,    6,    9,    0,    0,    0,
    0,    0, -253, -251, -250, -251, -251,    0,    0,    0,
 -249, -248, -247, -246, -245, -244, -243, -242, -241,    0,
    0,    0,    0, -240,    0, -238,    0, -238, -238,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -237,    0,
    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   14,    0,    4,   17,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
static const short yygindex[] = {                         0,
    0,  -14,    0,    0,    0,
};
#define YYTABLESIZE 260
static const short yytable[] = {                         15,
   31,   32,   33,   34,   35,   36,   37,   38,   39,   20,
   21,   48,   49,   18,   19,   42,   23,   24,   43,   25,
   26,   27,   28,   20,   29,   30,   15,   41,   44,   45,
   47,   50,   51,   52,   53,   54,   55,   56,   57,   58,
    0,   59,   60,    0,   61,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    2,    3,    4,    5,    6,
    7,    8,    9,   10,    0,    0,   11,   12,   13,   14,
};
static const short yycheck[] = {                         10,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  265,
  266,   26,   27,   10,  281,   10,  282,  281,   10,  282,
  281,  281,  281,   10,  282,  282,   10,  282,  282,  281,
  281,  281,  281,  281,  281,  281,  281,  281,  281,  281,
   -1,  282,  281,   -1,  282,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  256,  257,  258,  259,  260,
  261,  262,  263,  264,   -1,   -1,  267,  268,  269,  270,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 282
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? (YYMAXTOKEN + 1) : (a))
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"FONTNAME","STICKY","GAP",
"MOUSEBIND","AUTOGROUP","BIND","COMMAND","IGNORE","YES","NO","BORDERWIDTH",
"MOVEAMOUNT","COLOR","SNAPDIST","ACTIVEBORDER","INACTIVEBORDER","URGENCYBORDER",
"GROUPBORDER","UNGROUPBORDER","MENUBG","MENUFG","FONTCOLOR","FONTSELCOLOR",
"ERROR","STRING","NUMBER","illegal-symbol",
};
static const char *yyrule[] = {
"$accept : grammar",
"grammar :",
"grammar : grammar '\\n'",
"grammar : grammar main '\\n'",
"grammar : grammar color '\\n'",
"grammar : grammar error '\\n'",
"string : string STRING",
"string : STRING",
"yesno : YES",
"yesno : NO",
"main : FONTNAME STRING",
"main : STICKY yesno",
"main : BORDERWIDTH NUMBER",
"main : MOVEAMOUNT NUMBER",
"main : SNAPDIST NUMBER",
"main : COMMAND STRING string",
"main : AUTOGROUP NUMBER STRING",
"main : IGNORE STRING",
"main : BIND STRING string",
"main : GAP NUMBER NUMBER NUMBER NUMBER",
"main : MOUSEBIND STRING string",
"color : COLOR colors",
"colors : ACTIVEBORDER STRING",
"colors : INACTIVEBORDER STRING",
"colors : URGENCYBORDER STRING",
"colors : GROUPBORDER STRING",
"colors : UNGROUPBORDER STRING",
"colors : MENUBG STRING",
"colors : MENUFG STRING",
"colors : FONTCOLOR STRING",
"colors : FONTSELCOLOR STRING",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 239 "parse.y"

struct keywords {
	const char	*k_name;
	int		 k_val;
};

int
yyerror(const char *fmt, ...)
{
	va_list		 ap;

	file->errors++;
	va_start(ap, fmt);
	fprintf(stderr, "%s:%d: ", file->name, yylval.lineno);
	vfprintf(stderr, fmt, ap);
	fprintf(stderr, "\n");
	va_end(ap);
	return (0);
}

int
kw_cmp(const void *k, const void *e)
{
	return (strcmp(k, ((const struct keywords *)e)->k_name));
}

int
lookup(char *s)
{
	/* this has to be sorted always */
	static const struct keywords keywords[] = {
		{ "activeborder",	ACTIVEBORDER},
		{ "autogroup",		AUTOGROUP},
		{ "bind",		BIND},
		{ "borderwidth",	BORDERWIDTH},
		{ "color",		COLOR},
		{ "command",		COMMAND},
		{ "font",		FONTCOLOR},
		{ "fontname",		FONTNAME},
		{ "gap",		GAP},
		{ "groupborder",	GROUPBORDER},
		{ "ignore",		IGNORE},
		{ "inactiveborder",	INACTIVEBORDER},
		{ "menubg",		MENUBG},
		{ "menufg",		MENUFG},
		{ "mousebind",		MOUSEBIND},
		{ "moveamount",		MOVEAMOUNT},
		{ "no",			NO},
		{ "selfont", 		FONTSELCOLOR},
		{ "snapdist",		SNAPDIST},
		{ "sticky",		STICKY},
		{ "ungroupborder",	UNGROUPBORDER},
		{ "urgencyborder",	URGENCYBORDER},
		{ "yes",		YES}
	};
	const struct keywords	*p;

	p = bsearch(s, keywords, sizeof(keywords)/sizeof(keywords[0]),
	    sizeof(keywords[0]), kw_cmp);

	if (p)
		return (p->k_val);
	else
		return (STRING);
}

#define MAXPUSHBACK	128

u_char	*parsebuf;
int	 parseindex;
u_char	 pushback_buffer[MAXPUSHBACK];
int	 pushback_index = 0;

int
lgetc(int quotec)
{
	int		c, next;

	if (parsebuf) {
		/* Read character from the parsebuffer instead of input. */
		if (parseindex >= 0) {
			c = parsebuf[parseindex++];
			if (c != '\0')
				return (c);
			parsebuf = NULL;
		} else
			parseindex++;
	}

	if (pushback_index)
		return (pushback_buffer[--pushback_index]);

	if (quotec) {
		if ((c = getc(file->stream)) == EOF) {
			yyerror("reached end of file while parsing "
			    "quoted string");
			if (file == topfile || popfile() == EOF)
				return (EOF);
			return (quotec);
		}
		return (c);
	}

	while ((c = getc(file->stream)) == '\\') {
		next = getc(file->stream);
		if (next != '\n') {
			c = next;
			break;
		}
		yylval.lineno = file->lineno;
		file->lineno++;
	}

	while (c == EOF) {
		if (file == topfile || popfile() == EOF)
			return (EOF);
		c = getc(file->stream);
	}
	return (c);
}

int
lungetc(int c)
{
	if (c == EOF)
		return (EOF);
	if (parsebuf) {
		parseindex--;
		if (parseindex >= 0)
			return (c);
	}
	if (pushback_index < MAXPUSHBACK-1)
		return (pushback_buffer[pushback_index++] = c);
	else
		return (EOF);
}

int
findeol(void)
{
	int	c;

	parsebuf = NULL;

	/* skip to either EOF or the first real EOL */
	while (1) {
		if (pushback_index)
			c = pushback_buffer[--pushback_index];
		else
			c = lgetc(0);
		if (c == '\n') {
			file->lineno++;
			break;
		}
		if (c == EOF)
			break;
	}
	return (ERROR);
}

int
yylex(void)
{
	u_char	 buf[8096];
	u_char	*p;
	int	 quotec, next, c;
	int	 token;

	p = buf;
	while ((c = lgetc(0)) == ' ' || c == '\t')
		; /* nothing */

	yylval.lineno = file->lineno;
	if (c == '#')
		while ((c = lgetc(0)) != '\n' && c != EOF)
			; /* nothing */

	switch (c) {
	case '\'':
	case '"':
		quotec = c;
		while (1) {
			if ((c = lgetc(quotec)) == EOF)
				return (0);
			if (c == '\n') {
				file->lineno++;
				continue;
			} else if (c == '\\') {
				if ((next = lgetc(quotec)) == EOF)
					return (0);
				if (next == quotec || c == ' ' || c == '\t')
					c = next;
				else if (next == '\n') {
					file->lineno++;
					continue;
				} else
					lungetc(next);
			} else if (c == quotec) {
				*p = '\0';
				break;
			}
			if (p + 1 >= buf + sizeof(buf) - 1) {
				yyerror("string too long");
				return (findeol());
			}
			*p++ = c;
		}
		yylval.v.string = xstrdup(buf);
		return (STRING);
	}

#define allowed_to_end_number(x) \
	(isspace(x) || x == ')' || x ==',' || x == '/' || x == '}' || x == '=')

	if (c == '-' || isdigit(c)) {
		do {
			*p++ = c;
			if ((unsigned)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && isdigit(c));
		lungetc(c);
		if (p == buf + 1 && buf[0] == '-')
			goto nodigits;
		if (c == EOF || allowed_to_end_number(c)) {
			const char *errstr = NULL;

			*p = '\0';
			yylval.v.number = strtonum(buf, LLONG_MIN,
			    LLONG_MAX, &errstr);
			if (errstr) {
				yyerror("\"%s\" invalid number: %s",
				    buf, errstr);
				return (findeol());
			}
			return (NUMBER);
		} else {
nodigits:
			while (p > buf + 1)
				lungetc(*--p);
			c = *--p;
			if (c == '-')
				return (c);
		}
	}

/* Similar to other parse.y copies, but also allows '/' in strings */
#define allowed_in_string(x) \
	(isalnum(x) || (ispunct(x) && x != '(' && x != ')' && \
	x != '{' && x != '}' && x != '<' && x != '>' && \
	x != '!' && x != '=' && x != '#' && x != ','))

	if (isalnum(c) || c == ':' || c == '_' || c == '*' || c == '/') {
		do {
			*p++ = c;
			if ((unsigned)(p-buf) >= sizeof(buf)) {
				yyerror("string too long");
				return (findeol());
			}
		} while ((c = lgetc(0)) != EOF && (allowed_in_string(c)));
		lungetc(c);
		*p = '\0';
		if ((token = lookup(buf)) == STRING)
			yylval.v.string = xstrdup(buf);
		return (token);
	}
	if (c == '\n') {
		yylval.lineno = file->lineno;
		file->lineno++;
	}
	if (c == EOF)
		return (0);
	return (c);
}

struct file *
pushfile(const char *name)
{
	struct file	*nfile;

	nfile = xcalloc(1, sizeof(struct file));
	nfile->name = xstrdup(name);

	if ((nfile->stream = fopen(nfile->name, "r")) == NULL) {
		warn("%s", nfile->name);
		free(nfile->name);
		free(nfile);
		return (NULL);
	}
	nfile->lineno = 1;
	TAILQ_INSERT_TAIL(&files, nfile, entry);
	return (nfile);
}

int
popfile(void)
{
	struct file	*prev;

	if ((prev = TAILQ_PREV(file, files, entry)) != NULL)
		prev->errors += file->errors;

	TAILQ_REMOVE(&files, file, entry);
	fclose(file->stream);
	free(file->name);
	free(file);
	file = prev;
	return (file ? 0 : EOF);
}

int
parse_config(const char *filename, struct conf *xconf)
{
	int		 errors = 0;

	conf = xconf;

	if ((file = pushfile(filename)) == NULL) {
		return (-1);
	}
	topfile = file;

	yyparse();
	errors = file->errors;
	popfile();

	return (errors ? -1 : 0);
}
#line 643 "parse.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 5:
#line 88 "parse.y"
	{ file->errors++; }
break;
case 6:
#line 91 "parse.y"
	{
			if (asprintf(&yyval.v.string, "%s %s", yystack.l_mark[-1].v.string, yystack.l_mark[0].v.string) == -1) {
				free(yystack.l_mark[-1].v.string);
				free(yystack.l_mark[0].v.string);
				yyerror("string: asprintf");
				YYERROR;
			}
			free(yystack.l_mark[-1].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 8:
#line 104 "parse.y"
	{ yyval.v.number = 1; }
break;
case 9:
#line 105 "parse.y"
	{ yyval.v.number = 0; }
break;
case 10:
#line 108 "parse.y"
	{
			free(conf->font);
			conf->font = yystack.l_mark[0].v.string;
		}
break;
case 11:
#line 112 "parse.y"
	{
			if (yystack.l_mark[0].v.number == 0)
				conf->flags &= ~CONF_STICKY_GROUPS;
			else
				conf->flags |= CONF_STICKY_GROUPS;
		}
break;
case 12:
#line 118 "parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > UINT_MAX) {
				yyerror("invalid borderwidth: %d", yystack.l_mark[0].v.number);
				YYERROR;
			}
			conf->bwidth = yystack.l_mark[0].v.number;
		}
break;
case 13:
#line 125 "parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > INT_MAX) {
				yyerror("invalid movemount: %d", yystack.l_mark[0].v.number);
				YYERROR;
			}
			conf->mamount = yystack.l_mark[0].v.number;
		}
break;
case 14:
#line 132 "parse.y"
	{
			if (yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > INT_MAX) {
				yyerror("invalid snapdist: %d", yystack.l_mark[0].v.number);
				YYERROR;
			}
			conf->snapdist = yystack.l_mark[0].v.number;
		}
break;
case 15:
#line 139 "parse.y"
	{
			if (!conf_cmd_add(conf, yystack.l_mark[-1].v.string, yystack.l_mark[0].v.string)) {
				yyerror("command name/path too long");
				free(yystack.l_mark[-1].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[-1].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 16:
#line 149 "parse.y"
	{
			if (yystack.l_mark[-1].v.number < 0 || yystack.l_mark[-1].v.number > 9) {
				free(yystack.l_mark[0].v.string);
				yyerror("invalid autogroup: %d", yystack.l_mark[-1].v.number);
				YYERROR;
			}
			conf_autogroup(conf, yystack.l_mark[-1].v.number, yystack.l_mark[0].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 17:
#line 158 "parse.y"
	{
			conf_ignore(conf, yystack.l_mark[0].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 18:
#line 162 "parse.y"
	{
			if (!conf_bind_kbd(conf, yystack.l_mark[-1].v.string, yystack.l_mark[0].v.string)) {
				yyerror("invalid bind: %s %s", yystack.l_mark[-1].v.string, yystack.l_mark[0].v.string);
				free(yystack.l_mark[-1].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[-1].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 19:
#line 172 "parse.y"
	{
			if (yystack.l_mark[-3].v.number < 0 || yystack.l_mark[-3].v.number > INT_MAX ||
			    yystack.l_mark[-2].v.number < 0 || yystack.l_mark[-2].v.number > INT_MAX ||
			    yystack.l_mark[-1].v.number < 0 || yystack.l_mark[-1].v.number > INT_MAX ||
			    yystack.l_mark[0].v.number < 0 || yystack.l_mark[0].v.number > INT_MAX) {
				yyerror("invalid gap: %d %d %d %d",
				    yystack.l_mark[-3].v.number, yystack.l_mark[-2].v.number, yystack.l_mark[-1].v.number, yystack.l_mark[0].v.number);
				YYERROR;
			}
			conf->gap.top = yystack.l_mark[-3].v.number;
			conf->gap.bottom = yystack.l_mark[-2].v.number;
			conf->gap.left = yystack.l_mark[-1].v.number;
			conf->gap.right = yystack.l_mark[0].v.number;
		}
break;
case 20:
#line 186 "parse.y"
	{
			if (!conf_bind_mouse(conf, yystack.l_mark[-1].v.string, yystack.l_mark[0].v.string)) {
				yyerror("invalid mousebind: %s %s", yystack.l_mark[-1].v.string, yystack.l_mark[0].v.string);
				free(yystack.l_mark[-1].v.string);
				free(yystack.l_mark[0].v.string);
				YYERROR;
			}
			free(yystack.l_mark[-1].v.string);
			free(yystack.l_mark[0].v.string);
		}
break;
case 22:
#line 201 "parse.y"
	{
			free(conf->color[CWM_COLOR_BORDER_ACTIVE]);
			conf->color[CWM_COLOR_BORDER_ACTIVE] = yystack.l_mark[0].v.string;
		}
break;
case 23:
#line 205 "parse.y"
	{
			free(conf->color[CWM_COLOR_BORDER_INACTIVE]);
			conf->color[CWM_COLOR_BORDER_INACTIVE] = yystack.l_mark[0].v.string;
		}
break;
case 24:
#line 209 "parse.y"
	{
			free(conf->color[CWM_COLOR_BORDER_URGENCY]);
			conf->color[CWM_COLOR_BORDER_URGENCY] = yystack.l_mark[0].v.string;
		}
break;
case 25:
#line 213 "parse.y"
	{
			free(conf->color[CWM_COLOR_BORDER_GROUP]);
			conf->color[CWM_COLOR_BORDER_GROUP] = yystack.l_mark[0].v.string;
		}
break;
case 26:
#line 217 "parse.y"
	{
			free(conf->color[CWM_COLOR_BORDER_UNGROUP]);
			conf->color[CWM_COLOR_BORDER_UNGROUP] = yystack.l_mark[0].v.string;
		}
break;
case 27:
#line 221 "parse.y"
	{
			free(conf->color[CWM_COLOR_MENU_BG]);
			conf->color[CWM_COLOR_MENU_BG] = yystack.l_mark[0].v.string;
		}
break;
case 28:
#line 225 "parse.y"
	{
			free(conf->color[CWM_COLOR_MENU_FG]);
			conf->color[CWM_COLOR_MENU_FG] = yystack.l_mark[0].v.string;
		}
break;
case 29:
#line 229 "parse.y"
	{
			free(conf->color[CWM_COLOR_MENU_FONT]);
			conf->color[CWM_COLOR_MENU_FONT] = yystack.l_mark[0].v.string;
		}
break;
case 30:
#line 233 "parse.y"
	{
			free(conf->color[CWM_COLOR_MENU_FONT_SEL]);
			conf->color[CWM_COLOR_MENU_FONT_SEL] = yystack.l_mark[0].v.string;
		}
break;
#line 1054 "parse.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
