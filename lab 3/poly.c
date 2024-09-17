#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a term in a polynomial
struct Term {
    int coeff;
    int exp;
    struct Term* next;
};

// Function to create a new node (term)
struct Term* createNode(int coeff, int exp) {
    struct Term* newNode = (struct Term*)malloc(sizeof(struct Term));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into a polynomial linked list
struct Term* insertTerm(struct Term* head, int coeff, int exp) {
    struct Term* newNode = createNode(coeff, exp);

    if (head == NULL || exp > head->exp) {
        newNode->next = head;
        return newNode;
    }

    struct Term* temp = head;
    while (temp->next != NULL && temp->next->exp > exp) {
        temp = temp->next;
    }

    if (temp->exp == exp) {
        temp->coeff += coeff;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* p1 = poly1;
    struct Term* p2 = poly2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            result = insertTerm(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Function to evaluate a polynomial for a given value of x
int evaluatePolynomial(struct Term* poly, int x) {
    int result = 0;
    struct Term* temp = poly;
    while (temp != NULL) {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }
    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    struct Term* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL && temp->next->coeff >= 0) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    // Representing P(x) = 4x^3 + 3x^2 - 2x + 7
    poly1 = insertTerm(poly1, 4, 3);
    poly1 = insertTerm(poly1, 3, 2);
    poly1 = insertTerm(poly1, -2, 1);
    poly1 = insertTerm(poly1, 7, 0);

    // Representing Q(x) = -13x^3 + 9x^2 + 2x + 1
    poly2 = insertTerm(poly2, -13, 3);
    poly2 = insertTerm(poly2, 9, 2);
    poly2 = insertTerm(poly2, 2, 1);
    poly2 = insertTerm(poly2, 1, 0);

    printf("Polynomial P(x): ");
    displayPolynomial(poly1);

    printf("Polynomial Q(x): ");
    displayPolynomial(poly2);

    // Adding the two polynomials
    struct Term* sum = addPolynomials(poly1, poly2);
    printf("Sum of P(x) and Q(x): ");
    displayPolynomial(sum);

    // Evaluate polynomial P(x) for a given value of x
    int x = 2;
    int resultP = evaluatePolynomial(poly1, x);
    printf("P(%d) = %d\n", x, resultP);

    // Evaluate polynomial Q(x) for a given value of x
    int resultQ = evaluatePolynomial(poly2, x);
    printf("Q(%d) = %d\n", x, resultQ);

    return 0;
}
