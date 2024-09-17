#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 11

// Structure to store player details
struct Player {
    char name[50];
    int runsScored;
    int ballsFaced;
    int wicketsTaken;
    int isPlaying; // 1 if playing, 0 if not
};

// Structure to store team details
struct Team {
    char teamName[50];
    struct Player players[MAX_PLAYERS];
    int totalRuns;
    int wicketsFallen;
    int oversLeft;
};

// Structure to store match details
struct Match {
    struct Team team1;
    struct Team team2;
    int currentOver;
};

// Function to initialize a team
void initializeTeam(struct Team *team, char *name) {
    strcpy(team->teamName, name);
    team->totalRuns = 0;
    team->wicketsFallen = 0;
    team->oversLeft = 20; // Assuming a T20 match
    
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(team->players[i].name, "Player"); // Placeholder name
        team->players[i].runsScored = 0;
        team->players[i].ballsFaced = 0;
        team->players[i].wicketsTaken = 0;
        team->players[i].isPlaying = 1; // Assume all players are playing initially
    }
}

// Function to update match data
void updateMatchData(struct Match *match) {
    int runs, wicket;
    printf("Enter runs scored and if a wicket fell (0 for no, 1 for yes): ");
    scanf("%d %d", &runs, &wicket);

    match->team1.totalRuns += runs;
    if (wicket) {
        match->team1.wicketsFallen++;
    }

    match->currentOver++;
    match->team1.oversLeft--;
}

// Function to search for a player
void searchPlayer(struct Team *team, char *playerName) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(team->players[i].name, playerName) == 0) {
            printf("Player found: %s, Runs: %d, Balls: %d, Wickets: %d\n", 
                    team->players[i].name, team->players[i].runsScored, 
                    team->players[i].ballsFaced, team->players[i].wicketsTaken);
            return;
        }
    }
    printf("Player not found.\n");
}

// Function to delete a player from the team
void deletePlayer(struct Team *team, char *playerName) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (strcmp(team->players[i].name, playerName) == 0) {
            team->players[i].isPlaying = 0;
            printf("Player %s has been removed from the playing list.\n", playerName);
            return;
        }
    }
    printf("Player not found.\n");
}

// Function to display the scorecard
void displayScorecard(struct Match *match) {
    printf("\n--- Scorecard for %s ---\n", match->team1.teamName);
    printf("Total Runs: %d, Wickets Fallen: %d, Overs Left: %d\n", 
            match->team1.totalRuns, match->team1.wicketsFallen, match->team1.oversLeft);
    printf("Players:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (match->team1.players[i].isPlaying) {
            printf("%s: Runs - %d, Balls - %d\n", 
                    match->team1.players[i].name, 
                    match->team1.players[i].runsScored, 
                    match->team1.players[i].ballsFaced);
        }
    }
}

// Function to provide commentary
void provideCommentary(int runs, int wicket) {
    if (wicket) {
        printf("Wicket! The batsman is out.\n");
    } else if (runs == 4) {
        printf("It's a Four!\n");
    } else if (runs == 6) {
        printf("It's a Six!\n");
    } else if (runs == 0) {
        printf("No run.\n");
    } else {
        printf("%d runs scored.\n", runs);
    }
}

int main() {
    struct Match match;
    
    // Initialize teams
    initializeTeam(&match.team1, "Team A");
    initializeTeam(&match.team2, "Team B");

    // Example of adding custom player names (replace "Player" with actual names)
    strcpy(match.team1.players[0].name, "Player 1");
    strcpy(match.team1.players[1].name, "Player 2");
    // Add more players similarly

    // Simulate the match (simplified for example)
    for (int i = 0; i < 20; i++) { // 20 overs for example
        updateMatchData(&match);
        displayScorecard(&match);
        provideCommentary(match.team1.totalRuns, match.team1.wicketsFallen);
    }

    // Search for a player
    searchPlayer(&match.team1, "Player 1");

    // Delete a player if not playing
    deletePlayer(&match.team1, "Player 2");

    return 0;
}
