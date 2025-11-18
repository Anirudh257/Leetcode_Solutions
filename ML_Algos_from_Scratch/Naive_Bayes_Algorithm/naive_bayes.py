import numpy as np

class BernoulliNaiveBayes:
    def __init__(
        self, 
        alpha: 0.1
    ):
        """
            alpha: Laplace smoothing parameter.
        """
        self.alpha = alpha
        self.class_priors = None # shape: (n_classes, )
        self.feature_probs = None # shape: (n_classes, n_feats)
        self.classes = None

    def fit(
        self,
        X,
        y
    ):
        """
            Fit using Bayesian probability, measuring class_priors and feature_probs using
            the given email features X
        """

        # N: number of emails.
        # D: number of features (words in dictionary)
        N, D = X.shape
        self.classes = np.unique(y)

        num_classes = len(self.classes)

        self.class_priors = np.zeros(num_classes)
        self.feature_probs = np.zeros((num_classes, D))

        for idx, cls in enumerate(self.classes):

            # Compute the class prior.
            # P(y) = # emails with class y/total number of emails.

            # Select the rows of this class.
            X_cls = X[y == cls]

            # Number of Emails of class y.
            Nc = X_cls.shape[0]

            self.class_priors[idx] = Nc/N

            # Compute the feature probabilities.
            # P(x_i = 1 | y) = # emails of class y containing word x_i/# emails of class y.

            word_cnts = X_cls.sum(axis = 0) # D,

            self.feature_probs[idx] = (word_cnts + self.alpha)/(Nc + 2*self.alpha)

    def comp_log_posterior(
            self,
            x
    ):
        """
            Compute log p(y | x) up to a constant, for each class.
            x: (D,)
            returns: (C,) array of log-scores
        """

        C, D = self.feature_probs.shape
        log_priors = np.log(self.class_priors)

        # feature probs: (C, D)
        p = self.feature_probs

        # log p(x_i = 1 | y)
        log_p1 = np.log(p)

        # log p(x_i = 0 | y)
        log_p0 = np.log(1 - p)

        log_likelihood = (x * log_p1 + (1 - x) * log_p0).sum(axis=1)  # (C,)

        return log_priors + log_likelihood


    def predict(
            self, 
            X_test
        ):
        """
            X: (N, D)
            returns (N, ) predicted labels.
        """
        preds = []

        for sent in X_test:
            log_scores = self.comp_log_posterior(sent)
            cls_idx = np.argmax(log_scores)
            preds.append(self.classes[cls_idx])

        return np.array(preds)


def main():

    # Create a toy dataset of emails that need to be classified into spam/no spam.
    # 4 words in dictionary: {free, win, meeting}

    X = np.array([
        [1, 1, 0], # "free win" -> spam
        [1, 0, 0], # "free" -> spam
        [0, 0, 1], # "meeting" -> not spam
        [0, 1, 0] # win -> not spam.
    ])

    y = np.array([1, 1, 0, 0])

    nb = BernoulliNaiveBayes(alpha = 1.0)

    nb.fit(
        X = X,
        y = y
    )

    # Predict for a new email.
    X_new = np.array([
        [0, 1, 1] # "win, meeting"
    ])

    preds = nb.predict(X_test = X_new)

    print(preds)

if __name__ == "__main__":
    main()