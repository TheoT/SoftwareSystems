#include <glib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv) {
	GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
	int c;
	int i;

	FILE *file;
	file = fopen("text.txt", "r");
	char word[100];
	if (file) {
		c = getc(file);
	    while (c != EOF){
	    	i = 0;
	    	while (isalpha(c) && c != EOF){
	        	word[i]=c;
	        	i++;
	        	c = getc(file);
	        }
	        word[i]=0;
	        g_hash_table_insert(hash, g_strdup(word), g_hash_table_lookup(hash, word)+1); 
	        printf("%s\n", word);
	        
	        while (!isalpha(c) && c != EOF){
	        	c = getc(file);
	        }
	    }
	    fclose(file);
	}
	printf("%i\n",(int *) g_hash_table_lookup(hash, "mutually"));
	printf("%i\n",(int *) g_hash_table_lookup(hash, "the"));
	g_hash_table_destroy(hash);
	return 0;
}