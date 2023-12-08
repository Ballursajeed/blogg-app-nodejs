const { validateToken } = require("../services/auth");

function checkForAuthenticationCookie(cookieName) {
 return (req,res,next) => {
     const tokenCookieValue = req.cookies[cookieName]
     if (!tokenCookieValue) {
       return next();
     }
     try {
     const userPayload = validateToken(tokenCookieValue);
     req.user = userPayload;
     } catch (error) {
         console.error("Error validating token:", error);
      // Handle the error, e.g., send an unauthorized response
      return res.status(401).send("Unauthorized");
     }
     return next();

 };
};

module.exports = {
     checkForAuthenticationCookie,
}