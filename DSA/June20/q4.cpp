class Tweet{
    public:
    int tweetID;
    int userID;

    Tweet(int u, int t): userID(u),tweetID(t){};
};


class Twitter {
    vector<Tweet> tweets;
    vector<unordered_map<int,bool>> users{500};
    public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back(Tweet(userId,tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        int n = tweets.size();
        vector<int> output;
        for(int i = n-1; output.size()<10 && i >= 0; i--){
            if (tweets[i].userID == userId   || users[userId][tweets[i].userID] == true){
                output.push_back(tweets[i].tweetID);
            }
        }
        return output;
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followerId][followeeId] = false;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */