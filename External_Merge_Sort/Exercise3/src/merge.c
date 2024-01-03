#include <merge.h>
#include <stdio.h>
#include <stdbool.h>

void merge(int input_FileDesc, int chunkSize, int bWay, int output_FileDesc)
{
    CHUNK_Iterator chunkIterator;
    CHUNK_RecordIterator recordIterator;

    // Αρχικοποίηση του Iterator για τα τμήματα
    // ...

    // Επανάληψη για κάθε bWay τμήμα
    for (int i = 0; i < bWay; i++)
    {
        // Φόρτωση του επόμενου τμήματος
        loadNextChunk(&chunkIterator, chunkSize);

        // Επανάληψη για κάθε εγγραφή στο τρέχον τμήμα
        for (int j = 0; j < chunkSize; j++)
        {
            // Επιστροφή της επόμενης εγγραφής
            int recordValue = getNextRecordFromChunk(&recordIterator);

            // Εγγραφή της εγγραφής στο αρχείο εξόδου
            write(output_FileDesc, &recordValue, sizeof(int));
        }
    }
}
