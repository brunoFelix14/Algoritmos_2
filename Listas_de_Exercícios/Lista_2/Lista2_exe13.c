#include <stdio.h>
#include <string.h>

int main()
{
    int opc;

    do
    {
        printf("\n1-Cadastrar estação\n2-Cadastrar estilista\n3-Cadastrar roupa\n4-Roupa por estação\n5-Sair\nEscolha: ");
        scanf("%d", &opc);
        getchar();

        if (opc == 1)
        {
            FILE *f = fopen("Estação", "a");
            int c;
            char n[50];
            printf("Código da estação: "); scanf("%d", &c); getchar();
            printf("Nome da estação: "); fgets(n, 50, stdin);
            n[strcspn(n, "\n")] = '\0';
            fprintf(f, "Código da estação: %d\nNome da estação: %s\n\n", c, n);
            fclose(f);
            printf("Estação cadastrada!\n");
        }
        else if (opc == 2)
        {
            FILE *f = fopen("Estilista", "a");
            int c;
            char n[50];
            float s;
            printf("Código do estilista: "); scanf("%d", &c); getchar();
            printf("Nome do estilista: "); fgets(n, 50, stdin);
            n[strcspn(n, "\n")] = '\0';
            printf("Salário: "); scanf("%f", &s);
            fprintf(f, "Código do estilista: %d\nNome do estilista: %s\nSalário: %.2f\n\n", c, n, s);
            fclose(f);
            printf("Estilista cadastrado!\n");
        }
        else if (opc == 3)
        {
            int rc, re, ano;
            char d[100];
            printf("Código da roupa: "); scanf("%d", &rc); getchar();
            printf("Descrição: "); fgets(d,100,stdin); d[strcspn(d,"\n")]='\0';
            printf("Código do estilista: "); scanf("%d", &re);
            FILE *f = fopen("Estilista","r");
            int ok=0, c;
            char l[200];
            while (fgets(l,200,f))
            {
                if (sscanf(l,"Código do estilista: %d",&c)==1 && c==re)
                {
                    ok=1; break;
                }
            }
            fclose(f);
            if (!ok) { printf("Estilista não cadastrado!\n"); continue; }
            printf("Código da estação: "); scanf("%d", &re);
            f = fopen("Estação","r"); ok=0;
            while (fgets(l,200,f))
            {
                if (sscanf(l,"Código da estação: %d",&c)==1 && c==re)
                {
                    ok=1; break;
                }
            }
            fclose(f);
            if (!ok) { printf("Estação não cadastrada!\n"); continue; }
            printf("Ano: "); scanf("%d", &ano);
            FILE *r = fopen("Roupa","a");
            fprintf(r,"Código da roupa: %d\nDescrição: %s\nCódigo do estilista: %d\nCódigo da estação: %d\nAno: %d\n\n", rc, d, re, re, ano);
            fclose(r);
            printf("Roupa cadastrada!\n");
        }
        else if (opc == 4)
        {
            int re;
            printf("Código da estação: "); scanf("%d", &re);
            FILE *r = fopen("Roupa","r");
            char b[6][200]; int i;
            printf("\nRoupas da estação %d:\n", re);
            while (1)
            {
                for (i=0; i<5; i++) if (!fgets(b[i],200,r)) break;
                if (i<5) break;
                int ce; sscanf(b[3],"Código da estação: %d",&ce);
                if (ce==re)
                {
                    int es; sscanf(b[2],"Código do estilista: %d",&es);
                    FILE *e = fopen("Estilista","r");
                    char l[200], ne[100];
                    while (fgets(l,200,e))
                    {
                        if (sscanf(l,"Código do estilista: %d",&ce)==1 && ce==es)
                        {
                            fgets(ne,100,e);
                            break;
                        }
                    }
                    fclose(e);
                    printf("%s", b[0]);
                    printf("%s", b[1]);
                    printf("Estilista: %s", ne);
                    printf("%s", b[3]);
                    printf("%s", b[4]);
                    printf("\n");
                }
            }
            fclose(r);
        }
    }
    while (opc!=5);

    return 0;
}
