//Vote Counter using calloc()
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numCandidates, numVotes, vote;
    int *voteCount;

    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    // Allocate memory for candidates' vote counts using calloc
    voteCount = (int*) calloc(numCandidates, sizeof(int));

    if (voteCount == NULL) {
        printf("Memory allocation failed! Exiting.\n");
        return 1;  // Exit if memory not allocated
    }

    printf("Enter the number of votes: ");
    scanf("%d", &numVotes);

    printf("Vote for candidates (1 to %d):\n", numCandidates);
    for (int i = 0; i < numVotes; i++) {
        printf("Vote %d: ", i + 1);
        scanf("%d", &vote);

        if (vote >= 1 && vote <= numCandidates) {
            voteCount[vote - 1]++;
        } else {
            printf("Invalid vote! Skipped.\n");
        }
    }

    // Displaying the result
    printf("\n--- Voting Result ---\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("Candidate %d: %d votes\n", i + 1, voteCount[i]);
    }

    // Freeing the allocated memory
    free(voteCount);

    return 0;
}
