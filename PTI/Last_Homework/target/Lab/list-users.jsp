<%--
  Created by IntelliJ IDEA.
  User: Boris
  Date: 23.5.2020 г.
  Time: 10:40
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="models.User" %>
<%@ page import="models.UserRepository" %>
<html>
<head>
    <meta charset="ISO-8859-1">
    <title>Users</title>
    <link rel="stylesheet" href="./css/list-users.css">
</head>
<body>
<jsp:include page="navbar.jsp" />
<% UserRepository users = UserRepository.getInstance(); %>
<main class="row">
    <section class="inner-row">
        <section class="table-responsive">
            <table class="table table-hover">
                <thead>
                <tr>
                    <th>Name</th>
                    <th>Username</th>
                    <th></th>
                </tr>
                </thead>
                <tbody>
<%--                <c:forEach items="${users}" var="user">--%>
<%--                    <tr>--%>
<%--                        <td>${user.getName()}</td>--%>
<%--                        <td>${user.getUsername()}</td>--%>
<%--                        <td><a href="profile/${user.getId()}">Check Profile</a></td>--%>
<%--                    </tr>--%>
<%--                </c:forEach>--%>
                <% for (User user : users.getUsers()) { %>
                    <tr>
                        <td><%= user.getFullName() %></td>
                        <td><a href="profile/<%= user.getId() %>">Check Profile</a></td>
                    </tr>
                <% } %>
                </tbody>
            </table>
        </section>
    </section>
</main>
<jsp:include page="footer.jsp" />
</body>
</html>
